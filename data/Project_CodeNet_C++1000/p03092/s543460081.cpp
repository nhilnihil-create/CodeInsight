#include <bits/stdc++.h>

using namespace std;
const int N = 5e3 + 5;
int a[N], p[N];
long long dp[N][N], mn[N][N], A, B;

int main() {
    int n; cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) cin >> a[i], p[a[i]] = i;
    memset(dp, 63, sizeof dp);
    for (int x = 0; x <= n; x++) mn[0][x] = dp[0][x] = 0;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= n; x++) {
            dp[i][x] = (p[i] <= x ? A : B) + mn[i - 1][x];
            if (p[i] == x) dp[i][x] = min(dp[i][x], mn[i - 1][x - 1]);
            else if (x) dp[i][x] = min(dp[i][x], (p[i] < x ? A : B) + mn[i - 1][x - 1]);
            mn[i][x] = min((x ? mn[i][x - 1] : 1ll<<62), dp[i][x]);
        }
    }
    cout << mn[n][n] << "\n";

    return 0;
}
