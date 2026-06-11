#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mx = 2e5 + 5;

vector<pair<int , int> > adj[mx];
bool vis[mx];
int dis[mx];

void dfs(int src){
vis[src] = 1;
for(auto u : adj[src]){
    if(vis[u.first] == 0){
       dis[u.first] = (dis[src] + u.second);
       dfs(u.first);
    }
}
}

main(){
int n;
cin>>n;
for(int i=1 ; i<n ; i++){
    int u , v , w;
    cin>>u>>v>>w;
    adj[u].push_back({v , w});
    adj[v].push_back({u , w});
}

dfs(1);

for(int i=1 ; i<=n ; i++){
    cout<<dis[i]%2<<endl;
}
}
