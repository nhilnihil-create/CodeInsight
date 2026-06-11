#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<ll> cnt(5, 0);
    rep(i, N) {
        if (S[i][0] == 'M') {
            cnt[0]++;
        } else if (S[i][0] == 'A') {
            cnt[1]++;
        } else if (S[i][0] == 'R') {
            cnt[2]++;
        } else if (S[i][0] == 'C') {
            cnt[3]++;
        } else if (S[i][0] == 'H') {
            cnt[4]++;
        }
    }

    ll total = 0;
    rep(i, 5) {
        if (cnt[i] > 0) {
            total++;
        }
    }

    // repv(cnt) cout << *it << " ";
    // cout << endl;

    if (total < 3) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    rep(i, 5) {
        reps(j, i + 1, 5) {
            reps(k, j + 1, 5) { ans += cnt[i] * cnt[j] * cnt[k]; }
        }
    }

    cout << ans << endl;

    return 0;
}