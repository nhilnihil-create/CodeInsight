#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector V(N, vector(3, 0L));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> V.at(i).at(j);
    }
  }
  long ans = 0;
  for (int bit = 0; bit < 1 << 3; bit++) {
    vector sum(N, 0L);
    for (int i = 0; i < N; i++) {
      vector tmp = V.at(i);
      for (int j = 0; j < 3; j++) {
        if (bit >> j & 1) {
          tmp.at(j) *= -1;
        }
      }
      sum.at(i) = accumulate(tmp.begin(), tmp.end(), 0L);
    }
    sort(sum.rbegin(), sum.rend());
    ans = max(ans, accumulate(sum.begin(), sum.begin() + M, 0L));
  }
  cout << ans << "\n";
}