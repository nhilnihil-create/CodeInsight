#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  if (N >= M) {
    cout << 0 << endl;
    return 0;
  }
  
  int X[M];
  for (int i = 0; i < M; i++) {
    cin >> X[i];
  }
  
  sort(X, X+M);

  
  int dist[M-1];
  for (int i = 0; i < M-1; i++) {
    dist[i] = X[i+1]- X[i];
  }
  
  sort(dist, dist+M-1);
  
  int ans = 0;
  
  for (int i = 0; i < M-N; i++) {
    ans += dist[i];
  }
  
  cout << ans << endl;
  
  
}

