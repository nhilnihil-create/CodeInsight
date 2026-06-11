#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e5 + 5;

int n, a[MAXN][3 + 5], dp[MAXN][3 + 5];

int main() {
    IOS

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (j == k) {
                    continue;
                }

                dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
            }
        }
    }

    cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << '\n';
}