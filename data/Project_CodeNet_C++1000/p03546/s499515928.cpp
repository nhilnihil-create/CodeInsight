#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[500][500];

int main() {
    int H, W;
    cin >> H >> W;

    rep(i, 10) rep(j, 10) {
        int c;
        cin >> c;
        dp[i][j] = c;
    }

    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    for(int k = 0; k < 10; ++k) {
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < 10; ++j) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }

    int ans = 0;
    rep(i, H) rep(j, W) if (A[i][j] != -1) ans += dp[A[i][j]][1];
    cout << ans << endl;
}