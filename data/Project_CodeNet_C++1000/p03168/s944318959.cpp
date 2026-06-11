#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<double> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<vector<double>> dp(n+1, vector<double>(n+1, -1.0));

    function<double(int, int)> calc_dp = [&] (int i, int s) {
        if (i > s || i < 0 || s <= 0)
            return 0.0;

        if (i == 0 && s == 1) {
            return (1-p[0]);
        }

        if (i == 1 && s == 1) {
            return p[0];
        }

        if (dp[i][s] != -1)
            return dp[i][s];

        dp[i][s] = p[s-1] * calc_dp(i-1, s-1) + (1-p[s-1]) * calc_dp(i, s-1);
        return dp[i][s];
    };

    double ans = 0.0;
    for (int i = n/2 + 1; i <= n; ++i) {
        ans += calc_dp(i, n);
    }
    printf("%.10lf\n", ans);
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
