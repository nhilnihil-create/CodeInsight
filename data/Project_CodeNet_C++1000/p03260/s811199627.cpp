#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main (void){
    int a, b;
    cin >> a >> b;
    if(a * b * 3 % 2 == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
