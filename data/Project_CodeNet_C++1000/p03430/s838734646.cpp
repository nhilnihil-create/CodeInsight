#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 301;
int dp[MAXN][MAXN][MAXN];

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    int n = s.length();
    int mx = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; i + j <= n; j++) {
            for (int c = 0; c <= k; c++) {
                mx = max(mx, dp[i][j][c]);

                if (i + j + 1 <= n) {
                    dp[i + 1][j][c] = max(dp[i + 1][j][c], dp[i][j][c]);
                    dp[i][j + 1][c] = max(dp[i][j + 1][c], dp[i][j][c]);
                }
                if (i + j + 1 == n) {
                    dp[i + 1][j][c] = max(dp[i + 1][j][c], dp[i][j][c] + 1);
                    dp[i][j + 1][c] = max(dp[i][j + 1][c], dp[i][j][c] + 1);
                }

                // don't change
                if (i + j + 1 <= n && s[i] == s[n - 1 - j]) {
                    dp[i + 1][j + 1][c] = max(dp[i + 1][j + 1][c], dp[i][j][c] + 2);
                }

                // change
                if (i + j + 1 <= n && c + 1 <= k) {
                    dp[i + 1][j + 1][c + 1] = max(dp[i + 1][j + 1][c + 1], dp[i][j][c] + 2);
                }
            }
        }
    }

    cout << mx << endl;

    return 0;
}
