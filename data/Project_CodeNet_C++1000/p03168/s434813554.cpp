
// Problem: I - Coins
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_i
// Parsed on: 2020-09-07 11:36:13
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> p(n);
    for (auto &e : p) cin >> e;
    vector<vector<double>> dp(n+1, vector<double>(n+1));

    dp[0][0] = 0;
    dp[0][1] = 1 - p[0];
    dp[1][0] = p[0];

    for (int a = 0; a < n+1; a++) {
        for (int b = 0; b < n+1; b++) {
            if (a + b > n || a + b < 2) continue;
            dp[a][b] = ((a ? dp[a - 1][b] : 0) * p[a + b - 1]) +
                       ((b ? dp[a][b - 1] : 0) * (1 - p[a + b - 1]));
        }
    }

    double ans = 0;
    for (int a = 0; a < n+1; a++)
        for (int b = 0; b < n+1; b++) {
            if (a + b == n && a > b) ans += dp[a][b];
        }

    cout << fixed << setprecision(10) << ans;
    return 0;
}
