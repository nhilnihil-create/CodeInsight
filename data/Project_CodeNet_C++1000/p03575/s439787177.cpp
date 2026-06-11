/*
    Problem 86
    https://atcoder.jp/contests/abc075/tasks/abc075_c
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* class */
class DisjointSet {
public:
    vector<int> d;
    DisjointSet (int size) {d.assign(size, -1);}
    int find(int x) { return (d[x] < 0) ? x : d[x] = find(d[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x) {return -d[find(x)];}
};
/* global variables */
int cnt = 0;
int N, M;
vector<int> usedV, ord, lowLink;
vector<vector<int> > G, usedE;
/* function */
void dfs(int from) {
    usedV[from] = 1;
    ord[from] = lowLink[from] = cnt++;

    for (int to : G[from]) {
        if (!usedV[to]) {
            // nodeが使われていないならdfs
            usedE[from][to] = 1;
            dfs(to);
            // dfsが戻ってきたらlowlinkの更新
            lowLink[from] = min(lowLink[from], lowLink[to]);
        }
        // 辺が使われていなくて
        else if (!usedE[to][from]) {
            // 使われている頂点を訪れようとした場合
            // lowlinkの更新
            lowLink[from] = min(lowLink[from], ord[to]);
        }
    }
    return ;
}
int bridge(vector<pii> edges) {
    int ret = 0;
    int from, to;
    for (pii edge : edges) {
        from = edge.first, to = edge.second;
        if (ord[from] < lowLink[to]) ret++;
        if (ord[to] < lowLink[from]) ret++;
    }
    return ret;
}
void solve1() {
    cin >> N >> M;
    int u, v;
    vector<pii> edges;
    usedV.resize(MAX);
    ord.resize(MAX);
    lowLink.resize(MAX);
    G.resize(MAX, vector<int>(MAX));
    usedE.resize(MAX, vector<int>(MAX));
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        edges.push_back(pii(u, v));
    }
    dfs(0);
    int ans = bridge(edges);
    cout << ans << '\n';
}
void solve2() {
    cin >> N >> M;
    vector<pii> p(M);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        p[i] = pii(x, y);
    }
    int ans = 0;
    for (pii exclusion : p) {
        DisjointSet ds = DisjointSet(N);
        for (pii edge : p) {
            if (edge == exclusion) continue;
            ds.unite(edge.first, edge.second);
        }
        if (ds.size(0) != N) ans++;
    }
    cout << ans << '\n';
}
/* main */
int main(){
    // solve1();
    solve2();
}