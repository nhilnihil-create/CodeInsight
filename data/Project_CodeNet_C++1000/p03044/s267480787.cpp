#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> E(N);
  for (int i = 0; i < N - 1; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].push_back(make_pair(w, v));
    E[v].push_back(make_pair(w, u));
  }
  vector<int> c(N, -1);
  c[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E[v]){
      int d = P.first;
      int w = P.second;
      if (c[w] == -1){
        if (d % 2 == 0){
          c[w] = c[v];
        } else {
          c[w] = 1 - c[v];
        }
        Q.push(w);
      }
    }
  }
  for (int i = 0; i < N; i++){
    cout << c[i] << endl;
  }
}