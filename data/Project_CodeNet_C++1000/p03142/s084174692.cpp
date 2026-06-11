#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> in(N,0);
  vector<vector<int>> G(N,vector<int>(0));
  vector<vector<int>> P(N,vector<int>(0));  
  for(int i=0; i<N+M-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G.at(a).push_back(b);
    P.at(b).push_back(a);
    in[b]++;
  }
  queue<int> Q;
  vector<int> topo(0);
  for(int i=0; i<N; i++){
    if(in[i] == 0){
      Q.push(i);
      topo.push_back(i);
    }
  }
  while(Q.size()){
    int x = Q.front();
    Q.pop();
    for(int i=0; i<G[x].size(); i++){
      in[G[x][i]]--;
      if(in[G[x][i]] == 0){
        Q.push(G[x][i]);
        topo.push_back(G[x][i]);
      }
    }
  }
  
  vector<int> idx(N);
  for(int i=0; i<N; i++){
    int x = topo[i];
    idx[x] = i;
  }
  
  vector<int> par(N,-1);
  for(int i=0; i<N; i++){
    int t = topo[i];
    if(i == 0){
      par[t] = 0;
    }
    else{
      int IDX = -1;
      for(int j=0; j<P[t].size(); j++){
        IDX = max(IDX, idx[P[t][j]]);
      }
      par[t] = topo[IDX]+1;
    }
  }
  for(int i=0; i<N; i++){
    cout << par[i] << endl;
  }                                
}