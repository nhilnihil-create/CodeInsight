// 7/4
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
// using P = pair<int, int>;

int dp[15][2][2][2][2];  // 桁数、smaller、3、5、7
int P[3] = {3, 5, 7};

int main() {
    string N;
    cin >> N;
    vector<int> n;
    for (auto a : N) {
        n.push_back(a - '0');
    }
    int l = n.size();

    rep(i, 12) rep(smaller, 2) rep(x, 2) rep(y, 2) rep(z, 2) dp[i][smaller][x][y][z] = 0;
    dp[0][0][0][0][0] = 1;

    rep(i, l) {
        dp[i+1][1][0][0][0] += (dp[i][0][0][0][0] + dp[i][1][0][0][0]);

        rep(smaller, 2) {
            // if (smaller == 0)
            
            // x = 0の時
            // dp[i+1][smaller][0][0][0] += dp[i][smaller][0][0][0];

            rep(x, 2) rep(y, 2) rep(z, 2) {
                // for (int k = 0; P[k] <= (smaller ? 9 : n[i]); k++) {
                for (int k = 0; k < 3; k++) {
                    if (smaller == 0 && P[k] > n[i]) continue;
                    dp[i+1][smaller || P[k] < n[i]][x || P[k] == 3][y || P[k] == 5][z || P[k] == 7] += dp[i][smaller][x][y][z];
                }
            }
        }
    }

    // rep(i, l) {
    //     printf("dp[%d] = %d\n", i+1, dp[i+1][0][1][1][1] + dp[i+1][1][1][1][1]);
    // }

    cout << dp[l][0][1][1][1] + dp[l][1][1][1][1] << endl;
    return 0;
}