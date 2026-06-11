#include <iostream>
using namespace std;
int main () {
    char a, b, c;
    cin >> a >> b >> c;
    if (a=='1') a='9';
    else a='1';
    if (b=='1') b='9';
    else b='1';
    if (c=='1') c='9';
    else c='1';
    cout << a << b << c;
}