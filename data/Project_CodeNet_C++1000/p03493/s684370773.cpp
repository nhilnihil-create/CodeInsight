#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
    string t ;
    int s = 0 ;
    cin >> t ;
    if ( t[0] == '1'){
        s += 1 ;
    }
    if ( t[1] == '1'){
        s += 1 ;
    }
    if ( t[2] == '1'){
        s += 1 ;
    }
    cout << s ;
    return 0 ;
}
