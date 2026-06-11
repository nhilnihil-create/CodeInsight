#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int a = 700;
    getline(cin,s);
    if( s[0] == 'o' ) {
        a += 100;
    }
    if( s[1] == 'o' ) {
        a += 100;
    }
    if( s[2] == 'o' ) {
        a += 100;
    }
    cout << a;
}
