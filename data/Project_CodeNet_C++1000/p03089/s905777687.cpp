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
    vector<ll> b(N);
    rep(i, N) cin >> b[i];

    vector<ll> ans(N);
    rep(i, N) {
        bool flg = false;

        repr(j, SZ(b) - 1) {
            if (b[j] == j + 1) {
                flg = true;
                b.erase(b.begin() + j);
                ans[i] = j + 1;
                break;
            }
        }

        if (!flg) {
            cout << -1 << endl;
            return 0;
        }

        // repv(b) cout << *it << " ";
        // cout << endl;
    }

    reverse(ALL(ans));
    repv(ans) cout << *it << endl;

    return 0;
}