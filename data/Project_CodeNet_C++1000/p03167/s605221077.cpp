#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MOD = 1e9+7;

int n, m, dp[MAXN][MAXN];
char arr[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i) dp[i][j] += dp[i-1][j];
            if (j) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
            if (arr[i][j] == '#') dp[i][j] = 0;
        }
    }
    cout << dp[n-1][m-1] << "\n";
    return 0;
}
