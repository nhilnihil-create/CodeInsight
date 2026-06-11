#include <bits/stdc++.h>
using namespace std;

int64_t N,M,Z=1,A=0,B=0;
vector<vector<int>> G;
vector<int> seen;
void dfs(int a,int b){
  seen[a]=b;
  if(b==0){
    A++;
  }
  else{
    B++;
  }
  for(int x:G[a]){
    if(seen[x]==-1){
      dfs(x,(b+1)%2);
    }
    else if(seen[x]==b){
      Z=0;
    }
  }
}

int main() {
  cin>>N>>M;
  G.resize(N);
  seen.resize(N);
  for(int i=0;i<N;i++){
    seen[i]=-1;
  }
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0,0);
  if(Z){
    cout<<A*B-M<<endl;
  }
  else{
    cout<<N*(N-1)/2-M<<endl;
  }
}