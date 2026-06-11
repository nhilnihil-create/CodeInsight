#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
using pp=pair<ll,pair<ll,ll>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000

void dfs(Graph &G,int v,vector<int> &depth){
  for(auto nv:G[v]){
    if(depth[nv]==-1){
      depth[nv]=depth[v]+1;
      dfs(G,nv,depth);
    }
  }
}

int main(){
  int N;
  cin>>N;
  Graph G(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> depth(N,-1);
  depth[0]=0;
  dfs(G,0,depth);
  int v=0;
  for(int i=0;i<N;i++){
    if(depth[i]>depth[v]){
      v=i;;
    }
  }
  for(int i=0;i<N;i++){
    depth[i]=-1;
  }
  depth[v]=0;
  dfs(G,v,depth);
  int dia=0;
  for(int i=0;i<N;i++){
    dia=max(dia,depth[i]);
  }

  if(dia%3==1){
    cout<<"Second"<<endl;
  }else{
    cout<<"First"<<endl;
  }
}
