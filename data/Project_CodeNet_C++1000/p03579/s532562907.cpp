#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using eg = vector<vector<Edge>>;

int main()
{
    ios::sync_with_stdio(false);
    // 2部グラフか否かを判定する
    int N, M;
    cin >> N >> M;
    vvi graph(N);
    REP(i, M) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);  
    }
    bool isBi = true;   // bipartite
    vi color(N, -1);
    color[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto u: graph[v]) {
            if(color[u] != -1) {
                if(color[u] == color[v]) {
                    isBi = false;
                    break;
                }
                continue;
            }
            color[u] = (color[v]+1) & 1;
            q.push(u);
        }
        if(!isBi) break;
    }
    ll ans;
    if(!isBi) ans = (ll)N * (N - 1) / 2 - M;
    else {
        sort(color.begin(), color.end());
        ll count = upper_bound(color.begin(), color.end(), 0) - lower_bound(color.begin(), color.end(), 0);
        ans = count * (N - count) - M ;
    }
    cout << ans << endl;
    
    return 0;
}