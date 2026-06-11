#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

long long black, white;

// 二部グラフ判定
vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;
    if(cur) black++;
    else white++;
    for (auto next_v : G[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }

        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
        if (!dfs(G, next_v , 1 - cur)) return false;
    }
    return true;
}

int main() {
    // 頂点数と辺数
    long long N, M; cin >> N >> M;
    black = 0; white = 0;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) continue; // v が探索済みだったらスルー
        if (!dfs(G, v)) is_bipartite = false;
    }

    long long ans;
    if(!is_bipartite) ans = N*(N-1)/2 - M;
    else ans = black*white - M;
    cout << ans << endl;
    return 0;
}