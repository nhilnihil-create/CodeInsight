#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    mat c(2, vec(n));
    rep(i, 2) rep(j, n) cin >> c[i][j];

    int dp[2][110] = {};
    dp[0][0] = c[0][0];
    dp[1][0] = c[1][0] + c[0][0];

    rep(i, n-1) rep(j, 2) {
        if (j == 0) dp[j+1][i] = max(dp[j+1][i], dp[j][i] + c[j+1][i]);
        dp[j][i+1] = max(dp[j][i+1], dp[j][i] + c[j][i+1]);
    }

    cout << dp[1][n-1] << endl;
    return 0;
}