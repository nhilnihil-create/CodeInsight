#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;


int main(){
  int n;
  cin>>n;
  vector<vector<pair<int,int>>> g(n);
  rep(i,n-1){
    int u,v,w;
    cin>>u>>v>>w;
    u--; v--;
    g[u].pb({v,w});
    g[v].pb({u,w});
  }
  
  vector<int> dist(n,-1);
  queue<int> que;
  
  dist[0]=0;
  que.push(0);
  
  while(!que.empty()){
    int x=que.front();
    que.pop();
    
    for(auto nx:g[x]){
      if(dist[nx.first]!=-1) continue;
      dist[nx.first]=(dist[x]+nx.second)%2;
      que.push(nx.first);
    }
  }
  rep(i,n){
    if(dist[i]==0) cout<<0<<endl;
    else cout<<1<<endl;
  }
}
  