#include <iostream>
#include <cmath>

using namespace std;

double bn [6] = {1.25, -3.875, 2.125, 2.75, -3.5, 1.0}; //Polinomio inicial
double b[6];        //Guarda la primera division sintetica
double c[6];        //Guarda la segunda division sintetica
double det=0,
       raiz1=0,
       raiz2=0,
       deltR=0,
       deltS=0;

void division(double r, double s, int i){       //division sintetica 1
    b[i]=bn[i];
    double x[i+1];
    double y[i+1];
    x[i] = 0;
    y[i] = 0;
    i--;
    x[i] = bn[i+1]*r;                           //Guarda los valores al reves 
    y[i] = 0;
    b[i] = bn[i] + x[i] + y[i];
    i--;
    while (i>=0){
        x[i] = b[i+1]*r;
        y[i] = b[i+2]*s;
        b[i] = bn[i] + x[i] + y[i];
        i = i-1;
    }
}

void division2(double r, double s, int i){      //division sintentica 2
    c[i]=b[i];
    double x[i+1];
    double y[i+1];
    x[i] = 0;
    y[i] = 0;
    i = i-1;
    x[i] = b[i+1]*r;
    y[i] = 0;
    c[i] = b[i] + x[i] + y[i];
    i = i-1;
    while (i>=0){
        x[i] = c[i+1]*r;
        y[i] = c[i+2]*s;
        c[i] = b[i] + x[i] + y[i];
        i = i-1;
    }
}


void cramer(){
    det=pow(c[2], 2) - c[1]*c[3];               //Calcular el determinante
    deltR=((-b[1]*c[2])-(-b[0]*c[3]))/det;      //Calcula delta de r
    deltS=((c[2]*-b[0])-(c[1]*-b[1]))/det;      //Calcula delta de s
    
}
void devrs(double r, double s){
    do{
        division(r, s, 5);                      //Division sintetica 1
        /*for(int x=0; x<6;x++){
        cout << b[x] << endl;}*/
        division2(r, s, 5);                     //Division sintetica 2
        /*for(int x=0; x<6;x++){
        cout << c[x] << endl;}*/
        cramer();                               //Manda a llamar a cramer
        r=deltR+r;                              //Nueva r
        s=deltS+s;                              //Nueva 2
    }while(fabs(deltR/r)>0.01 && fabs(deltS/s)>0.01);   //Se hace mientras sea mayor al error
        for(int i = 5; i > 1; i--){
            cout << b[i] << " ";                //Nuevo polinomio
        }
        cout << "Nuevo polinomio" << endl;
        cout << "Nueva r: " << r << ", Nueva s: " << s <<endl;
        raiz1=(r+sqrt(pow(r,2)+(4*s)))/2;
        raiz2=(r-sqrt(pow(r,2)+(4*s)))/2;
}

int main(){
    devrs(-1, -1);
    cout << "Las raices son: " << raiz1 << ", " << raiz2 <<endl;

}

 