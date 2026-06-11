
// Problem: C - Vacation
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_c
// Parsed on: 2020-09-06 13:01:53
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
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
    vector<vector<int>> a(3, vector<int>(n));
    for (int t = 0; t < n; t++) cin >> a[0][t] >> a[1][t] >> a[2][t];

    vector<vector<int>> dp(3, vector<int>(n, numeric_limits<int>::min()));

    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0];
    dp[2][0] = a[2][0];

    for (int t = 1; t < n; t++) {
        for (int s = 0; s < 3; s++) {
            for (int r = 0; r < 3; r++) {
                if (s == r) continue;
                dp[s][t] = max(dp[s][t], dp[r][t - 1] + a[s][t]);
            }
        }
    }
    cout << max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1]));
    return 0;
}
