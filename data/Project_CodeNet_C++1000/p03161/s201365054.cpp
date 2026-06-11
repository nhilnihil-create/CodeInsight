#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
#define INF 1000000000000;

int main() {
    int n, k;
    cin >> n >> k;
    int h[n];
    rep(i,n) cin >> h[i];
    long long dp[110000];
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INF;
        for (int j = 1; j <= k; j++) {
            if (i-j < 0) {
                continue;
            }
            dp[i] = min(dp[i-j] + abs(h[i-j] - h[i]), dp[i]);
        }
    }
    cout << dp[n-1];
    return 0;
}
