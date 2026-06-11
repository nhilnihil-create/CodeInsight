#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll m, n;
    cin >> n >> m;
    ll a[n][3];
    rep(i, n) {
        rep(j, 3) {
            cin >> a[i][j];
        }
    }

    ll maxn = -(1LL << 60);

    rep(i, 8) {
        vector<ll> vec;
        ll sgn[3];
        rep(k, 3) {
            if (((1 << k) & i) == 0) {
                sgn[k] = 1;
            } else {
                sgn[k] = -1;
            }
        }
        rep(j, n) {
            ll s = 0;
            rep(k, 3) {
                s += sgn[k] * a[j][k];
            }
            vec.push_back(s);
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());

        ll ans = 0;
        rep(j, m) {
            ans += vec[j];
        }
        maxn = max(maxn, ans);
    }

    cout << maxn << endl;

    return 0;
}