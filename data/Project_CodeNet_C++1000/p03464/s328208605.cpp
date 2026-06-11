#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int K;
    cin >> K;
    vector<ll> a(K);
    rep(i, K) cin >> a[i];

    ll l = 0;
    ll r = 1LL << 60;
    while (r - l > 1) {
        ll c = (l + r) / 2;
        ll tmp = c;
        rep(i, K) tmp = (tmp / a[i]) * a[i];
        if (tmp >= 2) r = c;
        else l = c;
    }
    ll L = r;

    l = 0;
    r = 1LL << 60;
    while (r - l > 1) {
        ll c = (l + r) / 2;
        ll tmp = c;
        rep(i, K) tmp = (tmp / a[i]) * a[i];
        if (tmp > 2) r = c;
        else l = c;
    }
    ll R = l;

    if (L > R) cout << -1 << endl;
    else cout << L << " " << R << endl;
}