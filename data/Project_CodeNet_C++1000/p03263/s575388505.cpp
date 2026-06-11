#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

typedef pair<ll, ll> P;

int main() {
    INIT;

    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> a(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> a[i][j];

    vector<ll> b;
    rep(i, H) {
        if (i % 2 == 0) {
            rep(j, W) b.pb(a[i][j]);
        } else {
            repr(j, W - 1) b.pb(a[i][j]);
        }
    }

    // repv(b) cout << *it << " ";
    // cout << endl;

    vector<pair<P, P>> ans;

    rep(i, SZ(b) - 1) {
        if (b[i] % 2 == 1) {
            b[i]--;
            b[i + 1]++;

            ll yc = i / W;
            ll xc;
            if (yc % 2 == 0) {
                xc = i % W;
            } else {
                xc = (W - 1) - i % W;
            }
            xc++;
            yc++;

            ll yn = (i + 1) / W;
            ll xn;
            if (yn % 2 == 0) {
                xn = (i + 1) % W;
            } else {
                xn = (W - 1) - (i + 1) % W;
            }
            xn++;
            yn++;

            P pc = make_pair(yc, xc);
            P pn = make_pair(yn, xn);
            ans.pb({pc, pn});
        }
    }

    cout << SZ(ans) << endl;
    rep(i, SZ(ans)) {
        cout << ans[i].first.first << " " << ans[i].first.second << " "
             << ans[i].second.first << " " << ans[i].second.second << endl;
    }

    return 0;
}