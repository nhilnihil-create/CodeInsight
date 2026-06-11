#include<bits/stdc++.h>
using namespace std;

int n,m,dfn[10005],low[10005],dfncnt,ans=-1;
vector<int> g[10005];

void dfs(int x,int p){
    dfn[x]=low[x]=++dfncnt;
    for(int &y:g[x])if(!dfn[y]){
        dfs(y,x);
        low[x]=min(low[x],low[y]);
    }else if(y!=p){
        low[x]=min(low[x],dfn[y]);
    }
    ans+=dfn[x]==low[x];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1,-1);
    cout<<ans<<endl;

    return 0;
}