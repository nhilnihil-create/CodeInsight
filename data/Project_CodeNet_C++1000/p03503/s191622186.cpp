#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> F(N, vector<int>(10));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> F.at(i).at(j);
    }
  }
  vector<vector<int>> P(N, vector<int>(11));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 11; j++) {
      cin >> P.at(i).at(j);
    }
  }
  int ans = -1e9;
  for (int bit = 0; bit < 1 << 10; bit++) {
    if (__builtin_popcount(bit) == 0) continue;
    int tmp = 0;
    for (int i = 0; i < N; i++) {
      int cnt = 0;
      for (int j = 0; j < 10; j++) {
        if (bit >> j & 1 && F.at(i).at(j)) cnt++;
      }
      tmp += P.at(i).at(cnt);
    }
    ans = max(ans, tmp);
  }
  cout << ans << "\n";
}