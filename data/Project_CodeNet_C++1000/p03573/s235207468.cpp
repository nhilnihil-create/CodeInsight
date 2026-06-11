#include <iostream>

using namespace std;

int main () {

    float a, b , c ;

    cin >> a  >> b >> c ;

    if(a!=c && b!=c )
        cout << c << endl;
    if(b!=a && c!=a )
        cout << a << endl;
    if(a!=b && c!=b )
        cout << b << endl;


    return 0;
}
