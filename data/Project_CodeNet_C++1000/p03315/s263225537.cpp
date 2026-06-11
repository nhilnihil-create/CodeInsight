#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int b;
    b = 0;
    cin >> a;
    if( a[0] == '+' ){
        b++;
    }
    else {b--;};
    if( a[1] == '+' ){
        b++;
    }
    else {b--;};
    if( a[2] == '+' ){
        b++;
    }
    else {b--;};
    if( a[3] == '+' ){
        b++;
    }
    else {b--;};
    cout << b;

    return 0;
}
