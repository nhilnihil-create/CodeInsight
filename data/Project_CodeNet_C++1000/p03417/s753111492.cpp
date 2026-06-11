/**
 *    author:  FromDihPout
 *    created: 2020-08-18
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    
    if (n == 1 && m == 1) {
        cout << 1 << '\n';
    }
    else if (n == 1) {
        cout << m - 2 << '\n';
    }
    else if (n == 2) {
        cout << 0 << '\n';
    }
    else {
        cout << (long long) (n - 2) * (m - 2) << '\n';
    }
    return 0;
}