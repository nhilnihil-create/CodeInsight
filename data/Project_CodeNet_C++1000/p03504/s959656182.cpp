#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, C, M = 1e5;
  cin >> N >> C;
  vector<vector<int>> V(C, vector<int>(M));
  while (N--) {
    int s, t, c;
    cin >> s >> t >> c;
    s--, c--;
    V.at(c).at(s)++;
    if (t < M) V.at(c).at(t)--;
  }
  for (int i = 0; i < C; i++) {
    for (int j = 1; j < M; j++) {
      V.at(i).at(j) += V.at(i).at(j - 1);
    }
  }
  int ans = 0;
  for (int i = 0; i < M; i++) {
    int sum = 0;
    for (int j = 0; j < C; j++) {
      if (V.at(j).at(i) == 2) V.at(j).at(i) = 1;
      sum += V.at(j).at(i);
    }
    ans = max(ans, sum);
  }
  cout << ans << "\n";
}