#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int h, w;
  string s[55];
  const int dx[] = {0, 1, -1, 0};
  const int dy[] = {1, 0, 0, -1};

  cin >> h >> w;
  rep(i, h) cin >> s[i];

  int cnt = 0;
  rep(i, h)rep(j, w) {
    if (s[i][j] == '#') {
      bool sharp = false;
      for (int d = 0; d < 4; d++) {
        int x = i + dx[d];
        int y = j + dy[d];

        if (x < 0 || h <= x) continue;
        if (y < 0 || w <= y) continue;
        if (s[x][y] == '#') sharp = true;
      }
      if (!sharp) cnt++;
    }
  }

  if (cnt == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}