#include <iostream>
using namespace std;

int dividir(int* num){
    int resto = *num % 10;
    *num = *num / 10;
    return resto;
}

int main(){
    
    int n, a, b;
    int resto1=0, resto2=0;
    int aux;
    int suma=10e5, sum=10e5;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        a = n - i;
        b = i;
        
        while(a>10){
           aux = dividir(&a);
           resto1 += aux;
        }
        
        while(b>10){
            aux = dividir(&b);
            resto2 += aux;
        }
        
        suma = sum;
        sum = a + b + resto1 + resto2;
        if (sum > suma){
            sum = suma;
        }
        
    }
    
    cout << sum << endl;
    
    
    return 0;
}