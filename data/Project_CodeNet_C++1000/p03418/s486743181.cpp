/**
 *    author:  FromDihPout
 *    created: 2020-08-18
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for (int i = k + 1; i <= n; i++) {
        ans += (i - k) * (n / i);
        ans +=  max(n - ((n / i) * i + k) + 1, 0);
        if (k == 0) ans--;    }
    cout << ans << '\n';
    return 0;
}