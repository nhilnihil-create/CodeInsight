#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll inf = 1e9 + 9;

ll power(ll a, ll b, ll m = mod) {
    ll x = 1;
    while (b) {
        if (b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}

const int N = 2e5 + 9;
long long dp[N], a[N], sum[N];

signed main() {
    int n;
    cin >> n;
    n++;
    a[1] = 2e5 + 1;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }

    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (a[i] == a[i - 1]) {
            continue;
        }
        dp[i] += sum[a[i]];
        if (dp[i] >= mod) dp[i] -= mod;
        sum[a[i]] += dp[i - 1];
        if (sum[a[i]] >= mod) sum[a[i]] -= mod;
    }
    cout << dp[n] << "\n";
}
