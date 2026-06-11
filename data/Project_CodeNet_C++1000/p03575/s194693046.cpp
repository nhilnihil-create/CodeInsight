#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;

using Graph = vector<vector<int>>;
vector<bool> seen;
void dfs(const Graph &g, int v, P<int, int> &p){
    seen[v] = true;
    for(auto next_v : g[v]){
        if(seen[next_v]) continue;
        if(p.first == v && p.second == next_v) continue;
        if(p.second == v && p.first == next_v) continue;
        dfs(g, next_v, p);
    }
}

int main() {
    int n, m; cin >> n >> m;
    Graph g(n);
    V<P<int, int> > p(m);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        p[i] = make_pair(a, b);
    }

    int ans = 0;
    seen.assign(n, false);
    for(int i = 0; i < m; i++){
        dfs(g, 0, p[i]);

        bool flag = false;
        for(int i = 0; i < n; i++){
            if(seen[i]) continue;
            flag = true;
            break;
        }
        if(flag) ans++;
        seen.assign(n, false);
    }

    cout << ans << endl;
}
