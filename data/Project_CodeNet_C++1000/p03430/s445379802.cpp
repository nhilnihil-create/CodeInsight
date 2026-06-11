#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAXN = 300;
const int INF = 1000 * 1000 * 1000;

int dp[MAXN + 1][MAXN + 1][MAXN + 1];

void upd(int &x, int y) {
    x = max(x, y);
}

int main() {
    //cin.tie(0), ios::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = (int)s.size();
    int K;
    cin >> K;

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        dp[0][i][i] = 1;
        if (i + 1 < n) {
            if (s[i] == s[i + 1]) {
                dp[0][i][i + 1] = 2;
            } else {
                dp[0][i][i + 1] = 1;
                dp[1][i][i + 1] = 2;
            }
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int k = 0; k <= K; k++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                upd(dp[k][l][r], dp[k][l + 1][r]);
                upd(dp[k][l][r], dp[k][l][r - 1]);
                if (s[l] == s[r]) {
                    upd(dp[k][l][r], dp[k][l + 1][r - 1] + 2);
                }
                if (k > 0) {
                    upd(dp[k][l][r], max(dp[k - 1][l + 1][r - 1], dp[k - 1][l + 1][r - 1]) + 2);
                }
            }
        }
    }
    int ans = 0;
    for (int k = 0; k <= K; k++) {
        ans = max(ans, dp[k][0][n - 1]);
    }
    cout << ans << "\n";
    return 0;
}