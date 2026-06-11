#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    ll a, b; cin >> a >> b; b++;
    int po = floor(log2(b))+1;
    debug(po);
    vector<pair<ll, ll>> bits(po+1, {0, 0});
    rep(i, po+1) {
        ll m = pow(2, i);
        ll base = 0, add = 0;
        base = a / m;
        if (base%2!=0) {
            add = a % m;
        }
        base /= 2;
        bits[i].fi = base*m+add;
        base = 0, add = 0;
        base = b / m;
        if (base%2!=0) {
            add = b % m;
        }
        base /= 2;
        bits[i].se = base*m+add;
    }
    ll ans = 0;
    rep(i, po+1) {
        debug(pow(2,i), bits[i].fi, bits[i].se, bits[i].se-bits[i].fi);
        if ((bits[i].se-bits[i].fi)%2) ans += 1ll << i;
    }
    cout << ans << endl;
}