#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main (void){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //直接話せるとき
    if(abs(a - b) <= d && abs(b - c) <= d && abs(c - a) <= d){
        cout << "Yes" << endl;
    }else if(abs(c - a) <= d){
        cout << "Yes" << endl;
    }else if(abs(a - b) <= d && abs(b - c) <= d){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
