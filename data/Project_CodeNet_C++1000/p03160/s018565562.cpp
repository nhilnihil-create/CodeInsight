#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    const int inf = 1e9+7;
    vector<int> dp(n + 2, inf);
    dp[0] = 0;
    rep(i, n) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
    }
    cout << dp[n-1] << endl;
}