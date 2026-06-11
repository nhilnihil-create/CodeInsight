#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;
using ll = long long;
// 深さ優先探索
vector<ll> seen;  // 既に見たことがある頂点か記録
vector<ll> c;
int dfs(const Graph &G, int v, int id = 0) {
    seen[v] = c[id];
    for (auto e : G[v]) {
        if (seen[e.to] == 0) {  // 訪問済みでなければ探索
            id = dfs(G, e.to, id + 1);
        }
    }
    return id;
}

template <class T>
ostream &operator<<(ostream &s, vector<T> vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (i > 0) {
            s << ' ';
        }
        s << vec[i];
    }
    return s << endl;
}

int main() {
    int V, E;
    cin >> V;
    E = V - 1;
    Graph G(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back({b});
        G[b].push_back({a});
    }

    seen.resize(V, 0);  // 初期化
    c.resize(V, 0);
    for (int i = 0; i < V; i++) {
        cin >> c.at(i);
    }
    sort(c.begin(), c.end(), greater<ll>());

    dfs(G, 0);
    cout << accumulate(ALL(seen), 0LL) - seen[0] << endl;
    cout << seen;

    return 0;
}
