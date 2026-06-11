#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> dp(n + 1, 1e18);
    dp[0] = 0;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        dp[i + 1] = dp[0];
        dp[0] += a;
        for (int j = 0; j < i; ++j) {
            if (p[j] < p[i]) dp[i + 1] = min(dp[i + 1], dp[j + 1]);
            dp[j + 1] += p[j] < p[i] ? a : b;
        }
    }
    long long ans = 1e18;
    for (int i = 0; i <= n; ++i) ans = min(ans, dp[i]);
    cout << ans << '\n';
}