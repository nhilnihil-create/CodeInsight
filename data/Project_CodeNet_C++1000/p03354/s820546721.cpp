/// However long the night,
///     The dawn will break
/// ICPC next year

#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+5 ;

int n ,m ,arr[N] ,u ,v ;
vector<int> adj[N] ;
bool vis[N] ;
int vid ,cur[N] ;
vector<int> idx ;
void dfs(int p){
    vis[p] = 1 ;
    cur[arr[p]] = vid ;
    idx.push_back(p);
    for(int ch:adj[p]){
        if(vis[ch]) continue;
        dfs(ch) ;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",arr+i);
    while(m--){
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0 ;
    for(int i=1;i<=n;++i){
        if(vis[i]) continue ;
        idx.clear() ;
        ++vid ;
        dfs(i) ;
        for(int j:idx)
            if(cur[j]==vid) ++ans ;
    }
    cout << ans ;
    return 0;
}
