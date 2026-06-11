#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    double a,b; cin >> a >> b;
    if (a >= 13) {
        cout << b << endl;
    } else if (a >= 6) {
        cout << b / 2 << endl;
    } else {
        cout << 0 << endl;    
    }
}