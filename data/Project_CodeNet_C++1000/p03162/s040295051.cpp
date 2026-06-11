#include <bits/stdc++.h>

using namespace std;
 
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(4, 0));
    for (int i = 0; i < n; ++i) 
        cin >> v[i][1] >> v[i][2] >> v[i][3];

    // dp[i][j] maior felicidade no dia i não podendo fazer a atividade j
    // dp[i][j] = max(v[i][k] + dp[i-1][k]) para k != j
    int dp[n][4];
    memset(dp, -1, sizeof dp);

    function<int(int, int)> calc_dp = [&] (int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == 0) {
            int best = -1;
            for (int k = 1; k <= 3; ++k) {
                if (k != j) {
                    best = max(best, v[0][k]);
                }
            }
            return best;
        }

        int best = -1;
        for (int k = 1; k <= 3; ++k) {
            if (k != j) {
                best = max(best, v[i][k] + calc_dp(i-1, k));
            }
        }
        dp[i][j] = best;
        return dp[i][j];
    };

    cout << max(max(calc_dp(n-1, 1), calc_dp(n-1, 2)), calc_dp(n-1, 3)) << endl;
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
