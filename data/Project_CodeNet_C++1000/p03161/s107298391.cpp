#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    const int inf = 1e9+7;
    vector<int> dp(n + k, inf);
    dp[0] = 0;
    rep(i, n) {
        rep(j, k) dp[i+j+1] = min(dp[i+j+1], dp[i]+abs(h[i+j+1] - h[i]));
    }
    cout << dp[n-1] << endl;
}