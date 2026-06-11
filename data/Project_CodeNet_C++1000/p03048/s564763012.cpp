#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[4][3005];

int main() {
    vector<int> RGB(3);
    rep(i, 3) cin >> RGB[i];
    int N;
    cin >> N;

    rep(i, 4) rep(j, N + 1) dp[i][j] = 0;
    rep(i, 3) dp[i + 1][RGB[i]] = 1;

    rep(i, 3) rep(j, N + 1) {
        dp[i + 1][j] += dp[i][j];
        if (j - RGB[i] >= 0) dp[i + 1][j] += dp[i + 1][j - RGB[i]];
    }
    cout << dp[3][N] << endl;
}