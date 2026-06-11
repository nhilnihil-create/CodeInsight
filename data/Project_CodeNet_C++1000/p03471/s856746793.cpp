/**
 *    author:  FromDihPout
 *    created: 2020-08-11
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, y;
    cin >> n >> y;
    if (n * 10000 < y || n * 1000 > y) {
        cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
        return 0;
    }
    
    int c = y / 1000;
    int b = min((c - n) / 4, c / 5);
    c -= b * 5;
    int a = min(c + b - n, b / 2);
    b -= a * 2;
    if (a + b + c == n) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    else {
        cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
    }
    return 0;
}