#include <iostream>
using namespace std;

int main() {
    long long int a, b,  soma, sub, mult;
    cin >> a >> b;
    soma = a + b;
    sub = a - b;
    mult = a * b;

    if(soma > sub){
        if(soma > mult){
            cout << soma << endl;
        }
        else{
            cout << mult <<endl;
        }
    }
    else{
        if(sub > mult){
            cout << sub << endl;
        }
        else{
            cout << mult << endl;
        }
    }
    return 0;
}