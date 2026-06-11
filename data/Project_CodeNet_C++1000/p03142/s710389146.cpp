#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> G(N+1,vector<int>(0));
  vector<int> P(N+1,-1);
  vector<int> in(N+1,0);
  for(int i=0;i<N+M-1;i++){
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
    in[b]++;
  }
  
  int r;
  for(int i=1;i<=N;i++){
    if(in[i]==0) r = i;
  }
  P[r] = 0;
  queue<int> Q;
  Q.push(r);
  vector<bool> state(N+1,false);
  state[r] = true;
  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    for(int i=0;i<G[u].size();i++){
      int v = G[u][i];
      in[v]--;
      P[v] = u;
      if(in[v]==0 && state[v]==false){
        Q.push(v);
        state[v] = true;
      }
    }
  }
  
  for(int i=1;i<=N;i++) cout << P[i] << endl;
  return 0;
}
