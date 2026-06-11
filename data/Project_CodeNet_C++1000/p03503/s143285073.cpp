#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<vector<vector<int>>> F(N, vector<vector<int>>(5, vector<int>(2)));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 2; k++) cin >> F[i][j][k];
    }
  }
  vector<vector<int>> P(N, vector<int>(11));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 11; j++) cin >> P[i][j];
  }
  int ans = -1000000000;
  for (ll bit = 0; bit < (1<<10); bit++) {
    if (bit == 0) continue;
    vector<int> common(N, 0);
    int tmp = 0;
    for (int i = 0; i < 11; i++) {
      if (bit & (1<<i)) {
        for (int j = 0; j < N; j++) {
          if (F[j][i%5][i/5]) common[j]++;
        }
      }
    }
    for (int k = 0; k < N; k++) tmp += P[k][common[k]];
    if (tmp > ans) ans = tmp;
  }
  cout << ans << endl;
}
