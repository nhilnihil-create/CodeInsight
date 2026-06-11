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
    if (y > n * 10000 || y < n * 1000) {
        cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
        return 0;
    }
    
    int a = 0, b = 0, c = y / 1000;
    while (a + b + c > n) {
        if (a + b + c - 4 >= n && c - 5 >= 0) {
            b += 1;
            c -= 5;
        }
        else if (a + b + c - 1 >= n && b - 2 >= 0) {
            a += 1;
            b -= 2;
        }
        else {
            break;
        }
    }
    if (a + b + c == n) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    else {
        cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
    }
    return 0;
}