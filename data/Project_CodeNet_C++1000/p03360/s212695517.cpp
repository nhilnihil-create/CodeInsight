#include <iostream>
using namespace std;

int main() {
    long long int a, b, c, k;
    cin >> a >> b >> c >> k;
    int maior;
    if(a > b){
        if(a > c){
            maior = a;
        }
        else{
            maior = c;
        }
    }
    else{
        if(b > c){
            maior = b;
        }
        else{
            maior = c;
        }
    }

    int total = a + b + c - maior;


    for(int i =0; i < k; i++){
        maior += maior;
    }
    
    total += maior;
    cout << total <<endl;
}