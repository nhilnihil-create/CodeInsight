//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<int, pi> node;
#define oset tree<pi, null_type,greater<pi>, rb_tree_tag,tree_order_statistics_node_update>

#define N 100005
vector<int> adj[N];
vector<lli> we[N];
int ans[N];
bool vis[N];

void dfs(int u)
{
    vis[u] = 1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        lli w = we[u][i];
        if(vis[v] == 0){
            if(w%2){
                ans[v] = !ans[u];
            }
            else{
                ans[v] = ans[u];
            }
            dfs(v);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v;
        lli w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        we[u].push_back(w);
        we[v].push_back(w);
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
