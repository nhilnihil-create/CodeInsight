#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define int long long
int n,m,check=0,c[100005],num[2];
vector<int> graph[100005];
bool vis[100005];
void dfs(int u,int color){
    num[color]++;
    vis[u]=1;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(vis[v]==0){
            c[v]=1-color;
            dfs(v,1-color);
        }
    }
}
signed main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    c[1]=0;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<graph[i].size();j++){
            int v=graph[i][j];
            if(c[v]==c[i])
                check=1;
        }
    }
    if(check==1)
        cout<<n*(n-1)/2-m;
    else
        cout<<num[0]*num[1]-m;
}