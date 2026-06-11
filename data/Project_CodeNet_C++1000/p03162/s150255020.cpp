#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
#define repr(i,x,n) for (int i = x; i < n; ++i)
#define INF 999999999;

int n;
int util[110000][3];
long long dp[110000][3];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> util[i][0] >> util[i][1] >> util[i][2];

    for (int i = 1; i <= n; ++i) {
        for (int today = 0; today < 3; ++today) {
            for (int yesterday = 0; yesterday < 3; ++yesterday) {
                if (today == yesterday) {
                    continue;
                }
                dp[i][today] = max(dp[i][today], dp[i-1][yesterday] + util[i][today]);
            }
        }
    }
    long long ans = 0;
    rep(i,3) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
