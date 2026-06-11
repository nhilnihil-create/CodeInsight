#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') {
      bool flag = false;
      rep(k, 4) {
        ll nx = i + dx[k], ny = j + dy[k];
        if (0 <= nx && nx < h && 0 <= ny && ny < w && s[nx][ny] == '#')
          flag = true;
      }
      if (!flag) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
