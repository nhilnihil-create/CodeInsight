#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
    ll h,w,d; cin >> h >> w >> d;
    ll n = h * w;

    vector<pll> idx(n+1);
    for (ll i = 1; i < h + 1; i ++) {
        for (ll j = 1; j < w + 1; j ++) {
            ll a; cin >> a;
            idx[a] = {i + 1, j + 1};
        }
    }
    idx[0] = idx[d];

    vector<ll> D(n + 1,0);

    for (ll i = 0; i < d; i ++) {
        for (ll j = i; j <= n - d; j += d) {
            D[j + d] = D[j] + abs(idx[j].first - idx[j + d].first) + abs(idx[j].second - idx[j + d].second);
        }
      
    }

    ll q; cin >> q;
    for (ll i = 0; i <q ; i ++ ) {
        ll l,r; cin >> l >> r;
        cout << D[r] - D[l] << endl;
    } 
}