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
/* global variables */
int N, M;
int cnt = 0;
vector<int> ord(MAX, NIL), lowLink(MAX);
vector<vector<int> > G(MAX, vector<int>());
/* function */
void dfs(int from, int parent) {
    ord[from] = lowLink[from] = cnt++;
    for (int to : G[from]) {
        // DFS木の親を訪れようとしたら何もしない
        if (to == parent) continue;
        if (ord[to] == NIL) {
            // nodeが使われていないならdfs
            dfs(to, from);
            // dfsが戻ってきたらlowlinkの更新
            lowLink[from] = min(lowLink[from], lowLink[to]);
        }
        // 使われている頂点まだ使ってない辺でを訪れようとした場合
        else {
            // これが後退辺となるのでusedEは0のままにしておく
            // lowlinkの更新
            lowLink[from] = min(lowLink[from], ord[to]);
        }
    }
    return ;
}
void bridge(vector<pii> edges) {
    int from, to;
    int ans = 0;
    for (pii edge : edges) {
        from = edge.first, to = edge.second;
        if (ord[from] < lowLink[to] || ord[to] < lowLink[from])
            ans++;
    }

    cout << ans << '\n';
}
/* main */
int main(){
    cin >> N >> M;
    int u, v;
    vector<pii> edges;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        edges.push_back(pii(u, v));
    }
    dfs(0, -1);
    sort(edges.begin(), edges.end());
    bridge(edges);
}