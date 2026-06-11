#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, e;
    int c, d;

    cin >> a >>b;

    c=a; d=b; e = (( c + d ) % 2);
    
    cout << ( a + b ) /2 + e / 2 << endl;
}