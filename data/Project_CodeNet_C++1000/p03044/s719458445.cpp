#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = struct graph {
    vector<vector<int>> to;
    vector<vector<int>> cost;
    graph(int n) : to(n), cost(n) {}
};

#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define debug(x) cerr << "[DEBUG] " << #x << ": " << x << '\n';

// vector<int> color(1e5, -1);
vector<int> color;
bool dfs(const Graph &G) {
    queue<int> q;

    color[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        // 該当する頂点の間のコストを取り出す
        rep(i, G.to[v].size()) {
            int u = G.to[v][i];
            int w = G.cost[v][i];

            // 訪問済みであればスキップ
            if (color[u] != -1) continue; 
            
            // 距離の偶奇を判定してその頂点をqueueに入れる
            color[u] = (color[v] + w) % 2;
            q.push(u);
        }
    }

    return true;
}

int main() {
    // 頂点数と辺数
    int N; cin >> N;

    // グラフ入力受取
    Graph G(N);
    rep(i, N - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;

        // toに隣接している頂点入力
        G.to[a].push_back(b);
        G.to[b].push_back(a);

        // costを入力
        G.cost[a].push_back(w);
        G.cost[b].push_back(w);
    }

    // 探索
    color.assign(N, -1);
    dfs(G);

    // 解答の出力
    rep(i, N) cout << color[i] << "\n";
}