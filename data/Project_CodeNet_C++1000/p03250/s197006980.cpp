#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
    int a, b, c, n;
    cin >> a >> b >> c;

    if(a >= b){
        if(a <= c){
        cout << a + b + c - c + c * 10 << endl;
        }else{
        cout << a + b + c - a + a * 10 << endl;
        }
    }else if(b >= a){
        if(b <= c){
           cout << a + b + c - c + c * 10 << endl; 
        }else{
            cout << a + b + c - b + b * 10 << endl;
        }
    }else if(b >= c){
        if(b <= a){
            cout << a + b + c - a + a * 10 << endl; 
        }else{
            cout << a + b + c - b + b * 10 << endl;
        }
    }

    return 0;
}