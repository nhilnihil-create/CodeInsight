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

int main() {
    INIT;

    ll N;
    cin >> N;
    vector<vector<ll>> F(N, vector<ll>(10));
    rep(i, N) rep(j, 10) cin >> F[i][j];

    vector<vector<ll>> P(N, vector<ll>(11));
    rep(i, N) rep(j, 11) cin >> P[i][j];

    ll ans = -INF;
    ll days = 10;
    for (ll bit = 0; bit < (1 << days); bit++) {
        if (bit == 0) continue;
        ll sum = 0;

        for (ll k = 0; k < N; k++) {
            // cout << "k: " << k << endl;
            ll cnt = 0;
            for (ll i = 0; i < days; i++) {
                if ((bit & (1 << i))) {
                    if (F[k][i] == 1) {
                        cnt++;
                    }
                }
            }
            // cout << cnt << endl;
            sum += P[k][cnt];
        }

        chmax(ans, sum);
    }

    cout << ans << endl;

    return 0;
}