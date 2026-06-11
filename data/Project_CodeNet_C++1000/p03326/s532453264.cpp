#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];
    vector<ll> sum(n);
    ll ans = 0;
    rep(mask, 8) {
        int xm = mask>>0 & 1 ? 1 : -1;
        int ym = mask>>1 & 1 ? 1 : -1;
        int zm = mask>>2 & 1 ? 1 : -1;

        rep(i, n) sum[i] = x[i] * xm + y[i] * ym + z[i] * zm;
        sort(sum.begin(), sum.end(), greater<ll>());
        ll tmpAns = 0;
        rep(i, m) tmpAns += sum[i];
        ans = max(ans, tmpAns);
    }
    cout << ans << endl;
    return 0;
}