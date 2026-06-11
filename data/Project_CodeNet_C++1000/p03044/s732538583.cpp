#include <bits/stdc++.h>
using namespace std;

struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using graph = vector<vector<Edge>>;

vector<int> weight;
void DFS(const graph &G, int v, int sum){
  weight[v] = sum;
  for(auto e : G[v]){
    if(weight[e.to] == -1) DFS(G,e.to,sum+e.weight);
  }
}

int main(){
  int N;
  cin >> N;

  graph G(N);
  for(int i = 0; i < N-1; i++){
    int u,v,w;
    cin >> u >> v >> w;
    G[u-1].push_back(Edge(v-1,w));
    G[v-1].push_back(Edge(u-1,w));
  }
  weight.assign(N,-1);
  for(int v = 0; v < N; v++){
    if(weight[v] == -1){
      DFS(G,v,0);
    }
  }
  for(auto w : weight){
    if(w%2 == 0) cout << 0 << endl;
    else cout << 1 << endl;
  }
}