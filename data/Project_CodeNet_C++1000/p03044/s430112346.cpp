#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<pair<int,int>>> G;
vector<int> seen;
void dfs(int a,int b){
  seen[a]=b;
  for(auto x:G[a]){
    int s,t;
    tie(s,t)=x;
    if(seen[s]==-1){
      dfs(s,(b+t)%2);
    }
  }
}

int main() {
  cin>>N;
  G.resize(N);
  seen.resize(N);
  for(int i=0;i<N;i++){
    seen[i]=-1;
  }
  for(int i=1;i<N;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    G[b].push_back(make_pair(a,c));
    G[a].push_back(make_pair(b,c));
  }
  dfs(0,0);
  for(int i=0;i<N;i++){
    cout<<seen[i]<<endl;
  }
}