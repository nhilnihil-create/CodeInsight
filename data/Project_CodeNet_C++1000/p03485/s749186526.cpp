#include <iostream>
using namespace std;
int main(void){
    
    int a, b;
    cin >> a >> b;
    
    double amari = (a + b) / 2.0 - (a + b) / 2;    

    if(amari > 0){
        cout << (a + b) / 2 + 1 << endl;
    }
    else{
        cout <<  (a + b) / 2 << endl;
    }
    
}
