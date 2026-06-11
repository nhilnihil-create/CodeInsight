#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    ll ans = LLONG_MAX;
    rep(i, n) rep(j, n) rep(s, n) rep(t, n) {
        ll xl = x[i];
        ll xr = x[j];
        ll yl = y[s];
        ll yr = y[t];
        if (xl >= xr || yl >= yr) continue;
        int cnt = 0;
        rep(k, n) {
            if(xl <= x[k] && x[k] <= xr && yl <= y[k] && y[k] <= yr){
                cnt++;
            }
        }
        if(cnt >= k){
            ans = min(ans, (xr - xl) * (yr - yl));
        }
    }
    cout << ans << endl;
}