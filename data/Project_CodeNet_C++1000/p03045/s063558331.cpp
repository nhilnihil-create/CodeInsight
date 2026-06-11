#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    X--;
    Y--;
    E[X].push_back(Y);
    E[Y].push_back(X);
  }
  int ans = 0;
  vector<bool> used(N, false);
  for (int i = 0; i < N; i++){
    if (!used[i]){
      ans++;
      used[i] = true;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            Q.push(w);
          }
        }
      }
    }
  }
  cout << ans << endl;
}