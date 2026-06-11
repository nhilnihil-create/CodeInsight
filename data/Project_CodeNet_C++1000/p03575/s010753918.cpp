#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 100;
bool vis[N];
set<int> g[N];
int cc;
void dfs(int node){
    vis[node] = 1;
    for(auto x:g[node])
        if(!vis[x])
            dfs(x);
}
signed main(){
    int t = 1; //cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<pair<int,int>> edges;
        for (int i = 0; i < m; ++i)
        {
            int x,y; cin >> x >> y;
            edges.push_back({x,y});
            g[x].insert(y);
            g[y].insert(x);
        }
        int ans = 0;
        for(auto x:edges)
        {
            g[x.first].erase(x.second);
            g[x.second].erase(x.first);
            cc = 0;
            memset(vis,0,sizeof(vis));
            for(int i = 1; i <= n; i++)
                if(!vis[i])
                {
                    cc++;
                    dfs(i);
                }
            if(cc > 1)
                ans++;
            g[x.first].insert(x.second);
            g[x.second].insert(x.first);
        }
        cout << ans;
    }    
}