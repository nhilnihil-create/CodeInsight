#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
vector<int> e[M];
int vis[M],n,m;
void dfs(int x) {
    int l1 = e[x].size()-1;vis[x]=1;
    for(int i = 0; i <= l1 ; i ++){int v=e[x][i];if(vis[v]) continue;dfs(v);}
}
int main () {
    memset(vis,0,sizeof vis);
    cin >> n >> m;
    for (int i = 1;i <= m;i ++){int u,v,w;cin >> u >> v >> w;e[u].push_back(v);e[v].push_back(u);}
    int ans=0;
    for(int i = 1;i <= n;i++)
	if(!vis[i]){dfs(i);ans++;}
    cout<<ans<<endl;
    return 0;
}