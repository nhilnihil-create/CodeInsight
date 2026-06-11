#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int INF = 2e9;
const int MAXN = 1e5 + 5;

int n, k, h[MAXN], dp[MAXN];

int main() {
    IOS

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = INF;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k && i + j <= n; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }

    cout << dp[n] << '\n';
}