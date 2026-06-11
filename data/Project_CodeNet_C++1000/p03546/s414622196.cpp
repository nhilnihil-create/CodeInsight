// https://atcoder.jp/contests/abc079/tasks/abc079_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

const int INF = 1e15;

template <typename T> using Matrix = vector<vector<T>>;
template <typename T> void warshall_floyd(Matrix<T> &g, T INF) {
    REP(k, g.size()) REP(i, g.size()) REP(j, g.size()) {
        if (g[i][k] == INF || g[k][j] == INF)
            continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W, N = 10;
    cin >> H >> W;
    Matrix<int> g(N, vector<int>(N, INF));
    REP(i, N) REP(j, N) { cin >> g[i][j]; }
    vector<vector<int>> A(H, vector<int>(W));
    REP(i, H) REP(j, W) { cin >> A[i][j]; }
    // 全点対間最短路(Warshall-Floyd)
    warshall_floyd(g, INF);
    int ans = 0;
    REP(i, H) REP(j, W) {
        if (A[i][j] >= 0) {
            ans += g[A[i][j]][1];
        }
    }
    cout << ans << endl;

    return 0;
}
