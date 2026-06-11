#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

signed main() {
    cin >> N >> K;
    vi x(N), y(N);
    REP(i, N) {
        cin >> x[i] >> y[i];
    }
    vi xx = x, yy = y;
    sort(ALL(xx));
    sort(ALL(yy));
    UNIQUE(xx);
    UNIQUE(yy);
    map<int, int> mpx, mpy;
    REP(i, xx.size()) {
        mpx[xx[i]] = i + 1;
    }
    REP(i, yy.size()) {
        mpy[yy[i]] = i + 1;
    }
    W = x.size() + 1;
    H = y.size() + 1;
    vvi dp(H, vi(W));
    REP(i, N) {
        dp[mpy[y[i]]][mpx[x[i]]]++;
    }
    REP(h, H) {
        REP(w, W - 1) {
            dp[h][w + 1] += dp[h][w];
        }
    }
    REP(w, W) {
        REP(h, H - 1) {
            dp[h + 1][w] += dp[h][w];
        }
    }
    ans = LLINF;
    REP(uh, H) {
        REP(uw, W) {
            FOR(dh, 0, uh - 1) {
                FOR(dw, 0, uw - 1) {
                    if (dp[uh][uw] - dp[uh][dw] - dp[dh][uw] + dp[dh][dw] >= K) {
                        Y = yy[uh - 1] - yy[dh];
                        X = xx[uw - 1] - xx[dw];
                        ans = min(X * Y, ans);
                        dump(yy[uh - 1], xx[uw - 1], yy[dh], xx[dw], X, Y);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}