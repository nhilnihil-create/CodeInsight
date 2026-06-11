#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));

    constexpr int kInf = 1'000'000'000;

    function<int(int, int, int)> Dfs = [&](int l, int r, int c) {
        if (dp[l][r][c] >= 0) return dp[l][r][c];
        if (l == r) return 1;
        if (l == r - 1) {
            if (s[l] == s[r]) return 2;
            if (s[l] != s[r] && c > 0) return 2;
            return 1;
        }
        if (s[l] == s[r]) return dp[l][r][c] = Dfs(l + 1, r - 1, c) + 2;
        dp[l][r][c] = max(Dfs(l + 1, r, c), Dfs(l, r - 1, c));
        if (c > 0) dp[l][r][c] = max(dp[l][r][c], Dfs(l + 1, r - 1, c - 1) + 2);
        return dp[l][r][c];
    };

    int ans = 0;
    for (int i = 0; i <= k; ++i) ans = max(ans, Dfs(0, n - 1, i));
    cout << ans << "\n";
    return 0;
}
