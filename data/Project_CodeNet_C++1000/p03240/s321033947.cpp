
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

typedef pair<ll, pair<ll,ll>> P;
typedef vector<P> V;

ll calc_h(const P& p, int cx, int cy) {
    return abs(p.se.fi - cx) + abs(p.se.se - cy);
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N; cin >> N;

    V v(N);
    REP(i, N) {
        ll x, y; ll h;
        cin >> x >> y >> h;
        v[i] = {h, {x, y}};
    }

    sort(ALL(v), greater<>());

    REP(cx, 101) REP(cy, 101) {
        if (v[0].fi == 0) {
            // all 0
            ll h = INF;
            REP(i, N) {
                h = min(h, calc_h(v[i], cx, cy));
            }

            if (h == 0) continue;

            cout << cx << " " << cy << " " << h << endl;
            return 0;
        } else {
            // at least one elm is larger than 0.
            ll h = v[0].fi + calc_h(v[0], cx, cy);
            bool f = true;
            FOR(i, 1, N) {
                if (v[i].fi == 0) {
                    if (h - calc_h(v[i], cx, cy) > 0) {
                        f = false;
                        break;
                    }
                } else {
                    ll hi = v[i].fi + calc_h(v[i], cx, cy);
                    if (h != hi) {
                        f = false;
                        break;
                    }
                }
            }

            if (!f) continue;

            cout << cx << " " << cy << " " << h << endl;
            return 0;
        }
    }

}
