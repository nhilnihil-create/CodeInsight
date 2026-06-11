#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
struct edge{ll to, cost;};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define INF 1000000000000

using graph = vector<vector<ll>>;

vector<bool> seen;
void dfs(const graph &G, int v){
    seen[v] = true;

    for(auto next_v : G[v]){
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main(){
    ll n,m;
    graph g(n);
    cin >> n >> m;
    int ans = 0;
    seen.assign(n, false);
    for(int i = 0; i < m;i++){
        ll temp1,temp2,temp3;
        cin >> temp1 >> temp2 >> temp3;
        g[temp1-1].push_back(temp2-1);
        g[temp2-1].push_back(temp1-1);
    }
    for(int i = 0; i < n; i++){
        if(!seen[i]){
            dfs(g,i);
            ans++;
        }
    }
    cout << ans << endl;



}