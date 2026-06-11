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

    ll N, K;
    cin >> N >> K;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    vector<ll> sum_all;
    rep(i, N) {
        ll sum = 0;
        reps(j, i, N) {
            sum += a[j];
            sum_all.pb(sum);
        }
    }

    sort(ALL(sum_all), greater<ll>());

    // repv(sum_all) cout << *it << " ";
    // cout << endl;

    ll sum_max = (int)(log2(sum_all[0]));
    ll ans = 0;

    repr(i, sum_max) {
        ll bit = 1LL << i;
        vector<ll> cand;
        ll cnt = 0;

        rep(j, SZ(sum_all)) {
            if ((sum_all[j] & bit) > 0) {
                cand.pb(sum_all[j]);
                cnt++;
            }
        }

        if (cnt >= K) {
            sum_all = cand;
            ans |= bit;
        }

        // repv(sum_all) cout << *it << " ";
        // cout << endl;
    }
    cout << ans << endl;

    return 0;
}