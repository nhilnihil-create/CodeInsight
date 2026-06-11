#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD =  1000000007;
const ll INF = 1LL << 60;

using Graph = vector<vector<int>>;
Graph g;
vector<bool> seen;
void dfs(int v, int x, int y){
    seen[v] = true;
    for(auto next_v : g[v]){
        if(seen[next_v]) continue;
        if((v == x && next_v == y) || (v == y && next_v == x)) continue;
        dfs(next_v, x, y);
    }
}

int main() {
    int n, m; cin >> n >> m;
    g.resize(n);
    V<P<int, int> > v(m);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        v[i] = make_pair(a, b);
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        seen.assign(n, false);
        dfs(0, v[i].first, v[i].second);
        for(int i = 0; i < n; i++){
            if(seen[i]) continue;
            ans++;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
