#define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1e9;


pair<int, int> diametar (const vector<vector<int>> &G) {
    pair<int, int> res;
    int N = G.size();
    vector<bool> seen(N, false);
    vector<int> dist(N, INF);
    queue<int> que; que.emplace(0); dist[0] = 0;
    while (!que.empty()) {
        int u = que.front(); que.pop(); seen[u] = true;
        for (auto v : G[u]) if (!seen[v]) {
            dist[v] = dist[u] + 1;
            que.emplace(v);
        }
    }
    //for (auto d : dist) cout << d << " "; cout << endl;
    int node = -1, d = -INF;
    for (int i = 0; i < N; i++) {
        if (chmax(d, dist[i])) node = i;
    }
    //cout << node << endl;
    res.first = node;
    fill(dist.begin(), dist.end(), INF); dist[node] = 0;
    fill(seen.begin(), seen.end(), false);
    que.emplace(node);
    while (!que.empty()) {
        int u = que.front(); que.pop(); seen[u] = true;
        for (auto v : G[u]) if (!seen[v]) {
            dist[v] = dist[u] + 1;
            que.emplace(v);
        }
    }
    d = -INF;
    for (int i = 0; i < N; i++) {
        if (chmax(d, dist[i])) node = i;
    }
    res.second = node;
    return res;
}

bool dfs(const vector<vector<int>> &G, int u, int p, int fin, vector<int> &path) {
    if (u == fin) { path.emplace_back(fin); return true; }
    for (auto v : G[u]) if (v != p) {
        if (dfs(G, v, u, fin, path)) {
            path.emplace_back(u);
            return true;
        }
    }
    return false;
}

void dfs2(const vector<vector<int>> &G, int s, int p, vector<int> &dist) {
    if (G[s].size() == 1) { dist[s] = 0; return; }
    for (auto v : G[s]) if (v != p) {
        dfs2(G, v, s, dist);
    }
    for (auto v : G[s]) if (v != p) chmax(dist[s], dist[v]+1);
    return;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<pair<int, int>> edges;
    vector<int> P(N);
    
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        edges.emplace_back(a, b);
    }
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    sort(P.begin(), P.end());
    
    pair<int, int> dia = diametar(G);
    
    vector<int> path;
    dfs(G, dia.first, dia.first, dia.second, path);
    int sz = path.size();
    int s = path[sz/2];
    // s を根付き木としてdfsをして帰りがけに葉からの距離の最大値
    vector<int> dist(N, -INF);
    dfs2(G, s, s, dist);
    vector<pair<int, int>> dist2;
    for (int i = 0; i < N; i++) dist2.emplace_back(dist[i], i);
    sort(dist2.begin(), dist2.end());
    vector<int> node(N);
    for (int i = 0; i < N; i++) {
        int u = dist2[i].second;
        node[u] = P[i];
    }
    
    int sum = 0;
    for (auto e : edges) {
        int a, b; tie(a, b) = e;
        sum += min(node[a], node[b]);
    }
    
    printf("%d\n", sum);
    for (auto ans : node) printf("%d\n", ans);
    //for (auto v : path) cout << v << endl;
    //for (auto e : dist) cout << e << endl;
    return 0;
}