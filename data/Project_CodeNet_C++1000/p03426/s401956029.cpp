#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;


int main()
{
    ll H, W, D; cin >> H >> W >> D;
    vector<pair<ll, ll>> v(H*W+1);
    rep(i, H) rep(j, W) {
        ll num; cin >> num; v[num] = {i, j};
    }

    vll sum(H*W+1);
    for (ll i = 1; i <= D; i++) {
        ll base = i;
        while (base < H * W + 1) {
            if (base <= D) sum[base] = 0;
            else sum[base] = sum[base - D] + abs(v[base].first - v[base - D].first) + abs(v[base].second - v[base - D].second);
            base += D;
        }
    }

    ll Q; cin >> Q;
    vll l(Q), r(Q); rep(i, Q) cin >> l[i] >> r[i];

    rep(i, Q) {
        cout << sum[r[i]] - sum[l[i]] << endl;
    }
    return 0;
}