#include <bits/stdc++.h>

#define ll long long

using namespace std;
 
void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    function<int(int, int)> calc_dp = [&] (int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == t[j]) {
            dp[i][j] = 1 + calc_dp(i-1, j-1);
        } else {
            dp[i][j] = max(calc_dp(i-1, j), calc_dp(i, j-1));
        }

        return dp[i][j];
    };
    int sz = calc_dp(n-1, m-1);
    string ans(sz, '-');

    int index = sz-1;
    for (int i = n-1, j = m-1; i >= 0 && j >= 0; ) {
        if (s[i] == t[j]) {
            ans[index] = s[i];
            --i; --j; --index;
        } else if (i > 0 && dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
