#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;

string s;
int n, K;
int dp[305][305][305];
int solve(int i = 0, int j = n - 1, int k = K) {
    if (i > j) return 0;
    if (dp[i][j][k] == -1) {
        if (i == j) dp[i][j][k] = 1;
        else if (i + 1 == j) {
            if (s[i] == s[j])
                dp[i][j][k] = 2;
            else if (k) 
                dp[i][j][k] = 2;
            else
                dp[i][j][k] = 1;
        }
        else if (s[i] == s[j]) {
            dp[i][j][k] = 2 + solve(i + 1, j - 1, k);
        }
        else {
            dp[i][j][k] = max(solve(i, j - 1, k), solve(i + 1, j, k));
            if (k) {
                dp[i][j][k] = max(dp[i][j][k], 2 + solve(i + 1, j - 1, k - 1));
            }
        }
    }
    return dp[i][j][k];
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> s;
    n = s.size();
    cin >> K;
    cout << solve();
}
