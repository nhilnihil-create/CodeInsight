#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

ll k;
vector<ll> a;

ll f(ll x) {
    rep(i, k) x -= x % a[i];
    return x;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> k;
    a.resize(k);
    rep(i, k) cin >> a[i];

    ll mn, mx;
    ll ng = 0, ok = 1e15;
    while(ng + 1 < ok)
        (f(ng + ok >> 1) >= 2 ? ok : ng) = ng + ok >> 1;
    mn = ok;
    ok = 0;
    ng = 1e15;
    while(ok + 1 < ng)
        (f(ok + ng >> 1) <= 2 ? ok : ng) = ok + ng >> 1;
    mx = ok;

    if(mx < mn)
        cout << -1 << endl;
    else
        cout << mn << " " << mx << endl;

    return 0;
}