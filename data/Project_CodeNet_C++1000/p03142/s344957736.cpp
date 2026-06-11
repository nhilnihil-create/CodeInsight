/* topological_sort_DFS.cpp

    verified: AOJ GRL_4_B Topological Sort
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;

/* topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号
    計算量: O(|E|+|V|)
    返り値のサイズがグラフより小さければ閉路が存在する
    （大きなグラフではスタックオーバーフローの可能性があるので、dfsではなくbfsの方が良い）
 */
vector<int> topo_sort(const Graph &G) {  // bfs
    int n = (int)G.size();
    vector<int> ans(n);

    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e.to]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        int now = que.front();

        que.pop();
        for (auto e : G[now]) {
            ind[e.to]--;
            if (ind[e.to] == 0) {
                que.push(e.to);
                ans[e.to] = now + 1;
            }
        }
    }
    return ans;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    int V = N;
    int E = N - 1 + M;
    vector<int> s(E), t(E);
    for (int i = 0; i < E; i++) {
        cin >> s.at(i) >> t.at(i);
        s[i]--, t[i]--;
    }

    Graph G(V);
    for (int i = 0; i < E; i++) {
        G[s[i]].push_back({t[i]});
    }
    vector<int> ans = topo_sort(G);

    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}
