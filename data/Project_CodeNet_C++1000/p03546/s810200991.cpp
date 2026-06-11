#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int dijkstra(int s, int n, vector<vi> G) {
    vb used(n, false);
    vi d(n, INF);

    // sから1への最短経路
    d[s] = 0;
    while (true) {
        int v = -1;
        for (int u = 0; u < n; u++) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if (v == -1) break;
        used[v] = true;
        for (int u = 0; u < n; u++) {
            d[u] = min(d[u], d[v] + G[v][u]);
        }
    }

    return d[1];
}

int main() {
    int H, W; cin >> H >> W;
    vector<vi> C(10, vi(10));
    rep(i, 10) { rep(j, 10) { cin >> C[i][j]; } }

    vector<vi> A(H, vi(W));
    rep(i, H) { rep(j, W) { cin >> A[i][j]; } }

    vi minl(10);

    for (int i = 0; i < 10; i++) {
        minl[i] = dijkstra(i, 10, C);
    }

    map<int, int> G;
    rep (i, H) {
        rep(j, W) {
            G[A[i][j]]++;
        }
    }

    int res = 0;
    for (auto x : G) {
        if (x.first == -1 || x.first == 1) continue;
        res += minl[x.first] * x.second;
    }
    cout << res << endl;
}
