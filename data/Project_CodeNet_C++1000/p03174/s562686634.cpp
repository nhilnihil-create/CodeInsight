#include <bits/stdc++.h>
using namespace std;
const int MOD(1e9 + 7);
int n, p;
long long temp;
int main() {
    cin >> n;
    vector<int> dp(1 << n), g(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> p;
            g[i] |= p * (1 << j);
        }
    dp[0] = 1;
    for (int x = 1; x < (1 << n); ++x) {
        p = __builtin_popcount(x), temp = 0;
        for (int y = x & g[p - 1]; y; y &= y - 1)
            temp += dp[x & ~(y & -y)];
        dp[x] = temp % MOD;
    }
    cout << dp[(1 << n) - 1];
    return 0;
}