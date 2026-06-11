// 5/22
// ANT2-5-1. 二部グラフ判定
// 類題
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using LLP = pair<ll, ll>;

using Graph = vector<vector<int>>;

// 1か0。-1で初期化。
vector<int> color;

bool dfs(Graph &G, int v, int c) {
    color[v] = c;

    for (auto nv : G[v]) {
        // もし同じ色に塗られていたらfalse。
        if (color[nv] == c) return false;

        // もし塗られていなかったら、違う色で塗る。
        if (color[nv] == -1 && !dfs(G, nv, 1 - c)) return false;
    }

    return true;
}

int main() {
    ll N, M;
    cin >> N >> M;

    Graph G(N);

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    color.assign(N, -1);

    bool binary = dfs(G, 0, 0);

    if (binary) {
        ll num = 0;
        rep(i, N) {
            if (color[i] == 0) num++;
        }

        ll ans = num * (N - num) - M;
        cout << ans << endl;
    } else {
        ll ans = N * (N - 1) / 2 - M;
        cout << ans << endl;
    }
}
