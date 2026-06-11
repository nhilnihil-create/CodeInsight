#include <iostream>
#include <vector>
using namespace std;

using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;

// 入力
int N;
Graph G;

// res は答え
vector<int> res;

// v を c に塗る。p は v の親
void dfs(int v, int p, int c) {
    res[v] = c;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        if (e.second & 1) dfs(e.first, v, 1-c);
        else dfs(e.first, v, c);
    }
}

int main() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }
    res.assign(N, 0);
    dfs(0, -1, 1);
    for (auto v : res) cout << v << endl;
}
