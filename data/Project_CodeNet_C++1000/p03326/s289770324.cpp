#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n, m; cin >> n >> m;

    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> z(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }

    ll ans = 0;
    //全パターンをbit全探索
    for (ll bit = 0; bit < (1 << 3); ++bit) {
        vector<ll> pm(3);
        for (ll i = 0; i < 3; ++i) {
            if (bit & (1 << i)) {
                pm[i] = -1;
            } else {
                pm[i] = 1;
            }
        }

        vector<ll> s(n);
        for (ll i = 0; i < n; ++i) {
            s[i] = x[i] * pm[0] + y[i] * pm[1] + z[i] * pm[2];
        }

        sort(s.rbegin(), s.rend());

        ll sum = 0;
        for (ll i = 0; i < m; ++i) {
            sum += s[i];
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;
}