#include "bits/stdc++.h"
using namespace std;
#define int long long
bitset<2000009> dp;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 1;

    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int& i : a) cin >> i, sum += i;

    for (int i = 0; i < n; i++) {
        dp |= (dp << a[i]);
    }
    for (int i = sum / 2; i >= 0; i--) {
        if (dp[i]) {
            cout << sum - i << endl;
            break;
        }
    }
}

