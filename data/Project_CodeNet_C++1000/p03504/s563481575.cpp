#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, C;
  cin >> N >> C;
  vector<vector<bool>> ST(C, vector<bool>(1e5 + 1, false));
  rep(i, N) {
    int s, t, c;
    cin >> s >> t >> c;
    --c;
    for (int j = s; j <= t; ++j) ST[c][j] = true;
  }

  int answer = 0;
  rep(t, 1e5) {
    int cnt = 0;
    rep(i, C) {
      if (ST[i][t]) ++cnt;
    }
    answer = max(answer, cnt);
  }
  cout << answer << endl;
  return 0;
}