#include <bits/stdc++.h>
using namespace std;
using ll   = long long;
using pll  = pair<ll,ll>;
using vll  = vector<pll>;
using vvll = vector<vll>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define dmax(a,b) a=max(a,b)

int main() {
    int n; cin >> n;
    vll a(1<<n);
    vvll dp(1<<n, vll(2));
    rep(i,1<<n) {
        scanf("%ld", &a[i].first);
        a[i].second = i;
        dp[i][0] = a[i];
    }
    rep(b,1<<n) {
        rep(i,n) {
            int nb = b | (1<<i);
            if (nb == b) continue;
            set<pll> S;
            rep(j,2) {
                S.insert(dp[b][j]);
                S.insert(dp[nb][j]);
            }
            auto mx = S.rbegin();
            dp[nb][0] = *mx;
            dp[nb][1] = *++mx;
        }
    }
    ll ans = 0;
    rng(i,1,1<<n) {
        dmax(ans, dp[i][0].first + dp[i][1].first);
        cout << ans << endl;
    }
    return 0;
}
