#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, C;
  cin >> N >> C;
  int maxc = 100000;
  vector<vector<int>> CS(C, vector<int>(maxc + 1, 0));
  for (int i = 0; i < N; i++) {
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    CS[c][s - 1]++, CS[c][t]--;
  }
  for (int c = 0; c < C; c++) {
    for (int i = 0; i < maxc - 1; i++) {
      CS[c][i + 1] += CS[c][i];
    }
  }
  int res = 0;
  for (int i = 0; i < maxc - 1; i++) {
    int cnt = 0;
    for (int c = 0; c < C; c++) {
      if (CS[c][i] > 0) cnt++;
    }
    res = max(res, cnt);
  }
  cout << res << '\n';
  return 0;
}
