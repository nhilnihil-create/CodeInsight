#include <bits/stdc++.h>

using namespace std;
     
int main(){
    int numero;
    cin >> numero;
     
    int total = 0;
     
    while(numero){
        total = total + numero % 10;
        numero = numero / 10;
    }
     
    if(total == 1){
        cout << 10 << endl;

    }else{
        cout << total << endl;
        
    }
    return 0;
}