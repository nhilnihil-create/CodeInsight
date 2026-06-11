/**
 *    author:  FromDihPout
 *    created: 2020-08-17
**/

#include <bits/stdc++.h>
using namespace std;


int smallPow(int base, int num) {
    int x = base;
    while (x <= num) {
        x *= base;
    }
    return x /= base;
}

int withdrawls(int n) {
    if (n < 6) return n;
    
    int cnt6 = withdrawls(n - smallPow(6, n));
    int cnt9 = withdrawls(n - smallPow(9, n));
    return 1 + min(cnt6, cnt9);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    cout << withdrawls(n) << '\n';
    return 0;
}