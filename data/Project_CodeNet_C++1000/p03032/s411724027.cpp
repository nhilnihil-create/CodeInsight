#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  vector<int> V;
  for (int i = 0; i < N; i++) {
    int v; cin >> v;
    V.push_back(v);
  }

  multiset<int> minus[N+1][N+1];
  int cusL[N+1], cusR[N+1];
  cusL[0] = 0, cusR[0] = 0;

  for (int i = 0; i < min(K, N); i++) {
    if (i < N) {
      cusL[i+1] = cusL[i] + V[i];
      cusR[i+1] = cusR[i] + V[N-i-1];
      minus[i+1][0] = minus[i][0];
      if (V[i] < 0) {
        minus[i+1][0].insert(V[i]);
      }
        
      for (int j = 0; i + j < min(K, N); j++) {
        if (i+j < N) {
          minus[i][j+1] = minus[i][j];
          if (V[N-j-1] < 0) {
            minus[i][j+1].insert(V[N-j-1]);
          }
        }
      }
    }
  }

  int ans = -500000001;
  for (int l = 0; l <= min(K, N); l++) {
    for (int r = 0; l+r <= min(K, N); r++) {
      int tmp = cusL[l] + cusR[r];
      int k = K - (l+r);
      if (k > 0)
        for (auto it = minus[l][r].begin(); it != minus[l][r].end(); ++it) {
          tmp -= *it;
          if (--k == 0) break;
        }

      ans = max(ans, tmp);
    }
  }

  cout << ans << endl;

  return 0;
}