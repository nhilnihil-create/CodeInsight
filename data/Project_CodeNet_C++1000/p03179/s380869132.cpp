#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<bool> ls(n - 1);
    for (int i = 0; i < n - 1; i++) {
        char x;
        cin >> x;
        if (x == '<') ls[i] = true;
    }

    const int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (ls[i - 2]) {
                dp[i][j] = (dp[i - 1][j - 1] - dp[i - 1][0] + mod) % mod;
            } else {
                dp[i][j] = (dp[i - 1][i - 1] - dp[i - 1][j - 1] + mod) % mod;
            }
        }
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }

    cout << dp[n][n];
}

int main() {
    cout << fixed << setprecision(20);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
