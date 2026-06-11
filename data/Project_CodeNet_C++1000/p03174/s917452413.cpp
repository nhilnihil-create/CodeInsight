#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("unroll-loops")

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    const int MOD = 1000000007;
    int n;
    char p;
    cin >> n;
    int upbound = (1 << n);
    vector<int> g(n), dp(upbound);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> p;
            if(p=='1')
            g[i] |= (1 << j);
        }
    dp[0] = 1;
    for (int x = 1; x < upbound; ++x) {
        int p = __builtin_popcount(x), r = 0;
        for (int y = x & g[p - 1]; y; y &= y - 1)
        {
            r += dp[x & ~(y & -y)];
            if (r >= MOD) r -= MOD;
        }
        dp[x] = r;
    }
    cout << dp[upbound - 1];
}