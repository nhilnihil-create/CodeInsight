#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mxn = 1005;
int dp[mxn][mxn];
char grid[mxn][mxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1)
                continue;
            if (grid[i][j] == '#')
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[n][m] << '\n';
}