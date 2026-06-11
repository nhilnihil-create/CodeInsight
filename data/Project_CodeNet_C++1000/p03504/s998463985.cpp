#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, C; cin >> N >> C;
  // 小数をきらい、スケールを 2 倍拡大
  vector<vector<int>> imos(C, vector<int>(200002));
  for (int i = 0; i < N; i++) {
    int s, t, c; cin >> s >> t >> c; c--;
    imos.at(c).at(2*s-1)++;
    imos.at(c).at(2*t)--;
  }
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < 200001; j++) {
      imos.at(i).at(j+1) += imos.at(i).at(j);
    }
  }
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < 200002; j++) {
      // 同チャンネルで 2 番組が連続しているとき、
      // いっぺんに録画してしまえばよい
      if (imos.at(i).at(j)) imos.at(i).at(j) = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < 200002; i++) {
    int cnt = 0;
    for (int j = 0; j < C; j++) {
      cnt += imos.at(j).at(i);
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}