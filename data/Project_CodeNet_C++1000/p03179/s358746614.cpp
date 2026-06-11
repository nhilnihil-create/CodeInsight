#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define keep_calm_and_become_orange ios_base::sync_with_stdio(0)
#define utochka_po_imeni_jonathan_livingston cin.tie(0)
 
using namespace std;
 
void yes() {
    cout << "YES" << endl;
}
 
void no() {
    cout << "NO" << endl;
}
 
long long bp(long long a, long long p, long long mod) {
    if (p == 0) {
        return 1ll;
    } else if (p % 2 == 1) {
        return bp(a, p - 1, mod) * a % mod;
    } else {
        long long res = bp(a, p / 2, mod);
        return res * res % mod;
    }
}

const long long mod = 1e9 + 7;

void solve(int qq) { 
    int n; string s;
    cin >> n >> s;
    vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, 0));
    dp[1][1] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i < len; i++) {
            dp[len - 1][i] += dp[len - 1][i - 1];
            dp[len - 1][i] %= mod;
        }
        for (int last = 1; last <= len; last++) {
            int l, r;
            if (s[len - 2] == '>') {
                l = last;
                r = len - 1;
            } else {
                l = 1;
                r = last - 1;
            }
            if (l <= r) {
                dp[len][last] += (dp[len - 1][r] - dp[len - 1][l - 1] + mod);
                dp[len][last] %= mod;
            }
        }
    }
    long long ans = 0;
    for (int last = 1; last <= n; last++) {
        ans += dp[n][last];
        ans %= mod;
    }
    cout << ans << endl;
}   
 
int main()
{
    keep_calm_and_become_orange;
    utochka_po_imeni_jonathan_livingston;
 
    int t; t = 1;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}