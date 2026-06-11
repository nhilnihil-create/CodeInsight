#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> happy(n, vector<int>(3));
    rep(i, n) rep(j, 3) cin >> happy[i][j];
    const int inf = 1e9+7;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    rep(i, 3) dp[0][i] = happy[0][i];
    rep(i, n-1) {
        rep(j, 3) {
            rep(k, 3) {
                if (k == j) continue;
                dp[i+1][k] = max(dp[i+1][k], dp[i][j] + happy[i+1][k]);
            }
        }
    }
    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;
}