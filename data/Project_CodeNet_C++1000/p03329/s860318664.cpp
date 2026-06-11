#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 

int main() {
    ll n;
    cin >> n;
    vector<ll> pow6s;
    vector<ll> pow9s;
    ll cur = 1;
    while (cur <= n) {
        cur *= 6;
        pow6s.push_back(cur);
    }
    cur = 1;
    while (cur <= n) {
        cur *= 9;
        pow9s.push_back(cur);
    }
    
    vector<ll> dp(n+1, 1e9);
    dp[0] = 0;
    for (ll i = 0; i < n; ++i) {
        dp[i+1] = min(dp[i+1], dp[i] + 1);
        for (auto p : pow6s) {
            if (i+p > n) break;
            dp[i+p] = min(dp[i+p], dp[i] + 1);
        }
        for (auto p : pow9s) {
            if (i+p > n) break;
            dp[i+p] = min(dp[i+p], dp[i] + 1);
        }
    }
    cout << dp[n] << endl;
}
