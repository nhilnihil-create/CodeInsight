#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
vector<int> graph[100000],tpa;
int ptr;


void dfs(int u,bool *vis)
{
    if(vis[u])
        return;
    vis[u]=true;
    for(auto v:graph[u]){
        if(!vis[v]){
            dfs(v,vis);
        }
    }
    tpa[ptr]=u;
    ptr--;
}

void top_sort(int n)
{
    bool vis[n]={false};
    ptr=n-1;
    tpa.resize(n);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis);
        }
    }
}


int main(){

    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
    }
    top_sort(n);
    vector<int> dis(n);
    for(int u=0;u<n;u++){
        for(int v:graph[tpa[u]]){
            dis[v]=max(dis[v],1+dis[tpa[u]]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dis[i]);
    }
    cout<<ans;




return 0;
}
