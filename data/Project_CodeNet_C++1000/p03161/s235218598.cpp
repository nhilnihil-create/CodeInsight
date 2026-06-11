
// Problem: A - Frog 1
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_a
// Parsed on: 2020-09-06 12:44:28
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
    int n, k;
    cin >> n >> k;
    vector<int> dp(n, numeric_limits<int>::max()), arr(n);
    for (auto& e : arr) cin >> e;
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    for (int a = 2; a < n; a++) {
        for (int b = 1; b <= k; b++) {
            if (b <= a) {
                int smt = dp[a - b] + abs(arr[a - b] - arr[a]);
                dp[a] = min(dp[a], smt);
            }
        }
    }

    cout << dp[n - 1];
    return 0;
}
