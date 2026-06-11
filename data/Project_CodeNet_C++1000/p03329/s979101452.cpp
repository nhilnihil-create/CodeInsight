#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> atm;
    atm.push_back(1);
    int r = 1;
    while (r * 6 <= n) {
        r *= 6;
        atm.push_back(r);
    }
    r = 1;
    while (r * 9 <= n) {
        r *= 9;
        atm.push_back(r);
    }
    int m = atm.size();
    sort(atm.begin(), atm.end());
    vector<vector<int>> dp(m, vector<int>(n+1));
    rep(i, m) {
        rep(j, n+1) {
            if (i == 0) {
                dp[i][j] = j;
            } else {
                dp[i][j] = dp[i-1][j];
                if (j-atm[i] >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-atm[i]]+1);
                    dp[i][j] = min(dp[i][j], dp[i][j-atm[i]]+1);
                }
            }
        }
    }
    cout << dp[m-1][n] << endl;
}