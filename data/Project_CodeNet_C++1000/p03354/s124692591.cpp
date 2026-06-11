#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> p(N);
  for (int i = 0; i < N; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<bool> used(N, false);
  int ans = 0;
  for (int i = 0; i < N; i++){
    if (!used[i]){
      used[i] = true;
      set<int> pos;
      pos.insert(i);
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            pos.insert(w);
            Q.push(w);
          }
        }
      }
      for (int x : pos){
        if (pos.count(p[x])){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}