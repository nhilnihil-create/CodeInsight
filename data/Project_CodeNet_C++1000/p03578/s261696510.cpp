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
    ll N, M;
    cin >> N;
    vector<ll> D(N);
    rep(i, N) cin >> D[i];
    cin >> M;
    vector<ll> T(M);
    rep(i, M) cin >> T[i];

    map<ll, ll> cd, ct;
    rep(i, N) { cd[D[i]]++; }
    rep(i, M) { ct[T[i]]++; }

    // for (auto elem : cd) {
    //     cout << elem.first << " " << elem.second << endl;
    // }
    // cout << "---" << endl;
    // for (auto elem : ct) {
    //     cout << elem.first << " " << elem.second << endl;
    // }

    rep(i, M) {
        // cout << cd[T[i]] << " / " << ct[T[i]] << endl;
        if (cd[T[i]] < ct[T[i]]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}