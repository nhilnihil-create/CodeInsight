#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
// const int INF = 1e8;
const ll INF = 1LL << 60;
typedef pair<int, int> P;

ll N, M;
typedef vector<vector<ll>> G;
G graph;
ll color[100050];

bool dfs(ll v, ll c) {
    color[v] = c; // 頂点v を cで塗る
    for (ll i = 0; i < graph[v].size(); i++) {
        // 隣接している頂点が同じ色なら false
        if (color[graph[v][i]] == c) return false;

        if (color[graph[v][i]] == 0 && !dfs(graph[v][i], -c)) return false;
    }

    // 全ての頂点をぬれた
    return true;
}


int main() {
    cin >> N >> M;
    graph = G(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll b = 0, w = 0;
    if (dfs(0, 1)) {
        rep(i, N) {
            if (color[i] == 1) {
                b++;
            } else if (color[i] == -1) {
                w++;
            }
        }
        cout << b * w - M << endl;
    } else {
        // 二部グラフではない場合
        cout << N * (N - 1) / 2 - M << endl;
    }
}