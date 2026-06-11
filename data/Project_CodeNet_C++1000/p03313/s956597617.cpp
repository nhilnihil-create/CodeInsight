#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define REP(i, n) FOR(i, 1, ll(n) + 1)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

struct MAX {
    ll mx1, mx2;
    void f(const ll a) {
        if(mx1 < a) {
            mx2 = mx1;
            mx1 = a;
        } else
            chmax(mx2, a);
    }
    void f(const MAX m) {
        f(m.mx1);
        f(m.mx2);
    }
    ll sum() { return mx1 + mx2; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<MAX> mx(1 << n);
    rep(i, 1 << n) {
        ll a;
        cin >> a;
        mx[i] = {a, -inf};
    }
    rep(j, n) {
        int x = 1 << j;
        rep(i, 1 << n) {
            if(!(i & x)) i |= x;
            mx[i].f(mx[i ^ x]);
        }
    }

    ll ret = 0;
    FOR(i, 1, 1 << n) {
        chmax(ret, mx[i].sum());
        cout << ret << endl;
    }
}