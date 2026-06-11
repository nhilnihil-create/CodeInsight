#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    ll ans = -1e12;
    vector<ll> x(N);
    vector<ll> y(N);
    vector<ll> z(N);
    rep(i, N) cin >> x[i] >> y[i] >> z[i];

    rep(b, 8) {
        vector<ll> anss(N, 0);
        rep(i, N) {
            ll sm = 0;
            sm += (b & (1 << 0)) ? x[i] : -x[i];
            sm += (b & (1 << 1)) ? y[i] : -y[i];
            sm += (b & (1 << 2)) ? z[i] : -z[i];
            anss[i] = sm;
        }
        sort(all(anss), greater<ll>());
        ll tmp = 0;
        rep(m, M) tmp += anss[m];
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}