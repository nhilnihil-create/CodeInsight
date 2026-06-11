#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
ll dfs(ll u, ll par, bool color, vector<vector<ll> > &graph, vector<vector<ll> > &ways) {
    if (ways[u][color] != -1)
        return ways[u][color];
    ll sum = 1;
    for (auto v : graph[u]) {
        if (v == par)
            continue;
        ll white = 0, black = 0;
        white = dfs(v, u, 1, graph, ways);
        if (color == 1) {
            black = dfs(v, u, 0, graph, ways);
        }
        sum = (sum % mod * (white + black) % mod) %mod ;
    }
    if (!sum)
        sum = 1;
    return ways[u][color] = sum;
}
int main() {
    ll n;
    cin>>n;
    vector<vector<ll> > graph(n+1);
    vector<vector<ll> > ways(n+1, vector<ll>(2, -1));
    for (int i = 1; i < n; i++) {
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll ans = 0;
    ans = (dfs(1, 0, 1, graph, ways) + dfs(1, 0, 0, graph, ways)) % mod;
    cout<<ans<<"\n";
    return 0;
}