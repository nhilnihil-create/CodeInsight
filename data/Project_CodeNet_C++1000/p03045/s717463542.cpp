#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool C[100050];
vector<int> G[100050];
void DFS(int x) {
  C[x] = true;
  for (int i = 0; i < G[x].size(); i++) {
    if (C[G[x][i]] == false) {
      DFS(G[x][i]);
    }
  }
  return;
}


int main() {
  int N,M;
  cin >> N >> M;
  int X[M],Y[M],Z[M];
  for (int i = 0; i < N; i++) {
    C[i] = false;
  }
  for (int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i] >> Z[i];
    X[i]--;
    Y[i]--;
    G[X[i]].push_back(Y[i]);
    G[Y[i]].push_back(X[i]);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (C[i] == false) {
      DFS(i);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}