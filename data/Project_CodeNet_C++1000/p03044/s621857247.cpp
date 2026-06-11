#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int color[100010];
vector<pair<int,int>> G[100010];

void dfs(int i,int c){
  color[i]=c;
  
  for(auto u:G[i]){
    if(color[u.first]!=-1) continue;
    if(u.second%2==0) dfs(u.first,c);
    else dfs(u.first,1-c);
  }
}

int main(){
  int n;
  cin>>n;
   
  int u,v,w;
  rep(i,n-1){
    cin>>u>>v>>w;
    G[u].push_back({v,w});
    G[v].push_back({u,w});
  }
  
  rep(i,n+1) color[i]=-1;
  
  dfs(1,0);
  rep(i,n) cout<<color[i+1]<<endl;
  
  return 0;
}