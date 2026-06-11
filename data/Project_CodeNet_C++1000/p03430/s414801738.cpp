#include "bits/stdc++.h"
using namespace std;
typedef long long li;

li dp[301][301][301];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    
    li k;
    cin >> k;
    
    const li n = s.size();
    for (int len = 0; len <= n; ++len) {
        for (int l = 0; l <= n; ++l) {
            const int r = l + len;
            if (r > n) {
                continue;
            }
            for (int kk = 0; kk <= k; ++kk) {
                if (kk > 0) {
                    dp[l][r][kk] = max(dp[l][r][kk], dp[l][r][kk - 1]);
                }
                if (len > 0) {
                    dp[l][r][kk] = max(dp[l][r][kk], dp[l + 1][r][kk]);
                    dp[l][r][kk] = max(dp[l][r][kk], dp[l][r - 1][kk]);
                }
                if (len == 1) {
                    dp[l][r][kk] = max(dp[l][r][kk], 1LL);
                }
                if (len >= 2) {
                    if (kk > 0) {
                        dp[l][r][kk] = max(dp[l][r][kk], dp[l + 1][r - 1][kk - 1] + 2);
                    }
                    if (s[l] == s[r - 1]) {
                        dp[l][r][kk] = max(dp[l][r][kk], dp[l + 1][r - 1][kk] + 2);
                    }
                }
            }
        }
    }    
    
    cout << dp[0][n][k] << endl;
    return 0;
}