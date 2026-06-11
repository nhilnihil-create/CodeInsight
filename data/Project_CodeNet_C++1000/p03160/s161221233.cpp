#include <bits/stdc++.h>
#include <vector>
#define rep(i,l,r) for(int i = l; i < r; ++i)
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll int> dp(n+1, 0);
    vector<int> h(n+1, 0);
    rep(i, 1, n+1) cin >> h[i];

    dp[2] = abs(h[1]-h[2]);

    for(int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i-2] + abs(h[i]-h[i-2]), dp[i-1] + abs(h[i]-h[i-1]));
    }

    // rep(i,n+1) cout << i+1 << " " << dp[i+1] << endl;

    cout << dp[n] << endl;
}
