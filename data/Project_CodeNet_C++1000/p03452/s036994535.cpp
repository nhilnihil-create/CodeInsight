#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> E(N);
  for (int i = 0; i < M; i++){
    int L, R, D;
    cin >> L >> R >> D;
    L--;
    R--;
    E[L].push_back(make_pair(D, R));
    E[R].push_back(make_pair(-D, L));
  }
  vector<int> d(N);
  vector<int> comp(N, -1);
  bool ok = true;
  for (int i = 0; i < N; i++){
    if (comp[i] == -1){
      comp[i] = i;
      d[i] = 0;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (auto P : E[v]){
          int dist = P.first;
          int w = P.second;
          if (comp[w] != -1){
            if (d[w] != d[v] + dist){
              ok = false;
            }
          } else {
            comp[w] = i;
            d[w] = d[v] + dist;
            Q.push(w);
          }
        }
      }
    }
  }
  if (ok){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}