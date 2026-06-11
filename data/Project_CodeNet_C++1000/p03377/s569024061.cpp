#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int check_text (string s, char x) ;
int main() {
    int a , b , x ;
    cin >> a >> b >> x ;
    if (x >= a && b >= (x-a)){
        cout << "YES" ;
    }
    else {
        cout << "NO" ;
    }
    return 0 ;
}