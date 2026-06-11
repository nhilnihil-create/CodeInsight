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

    vector<ll> x(N), y(N), h(N);
    ll start = -1;

    rep(i, N) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] > 0) start = i;
    }

    ll X = -1, Y = -1, H = -1;

    rep(i, 101) {
        rep(j, 101) {
            ll tmph = h[start] + abs(i - x[start]) + abs(j - y[start]);
            bool flg = true;

            rep(n, N) {
                if (h[n] > 0 && tmph != h[n] + abs(i - x[n]) + abs(j - y[n]))
                    flg = false;
                if (h[n] == 0 && tmph > abs(i - x[n]) + abs(j - y[n]))
                    flg = false;
            }

            if (flg) {
                X = i;
                Y = j;
                H = tmph;
            }
        }
    }

    cout << X << " " << Y << " " << H << endl;

    return 0;
}