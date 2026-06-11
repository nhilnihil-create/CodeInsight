#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> s[i][j];
    }
  }
  vector<int> dy = {-1, 1, 0, 0};
  vector<int> dx = {0, 0, -1, 1};

  rep(i, H) {
    rep(j, W) {
      bool check = false;
      if (s[i][j] == '.') continue;

      rep(k, 4) {
        if (i+dy[k] < 0 || i+dy[k] >= H || j+dx[k] < 0 || j + dx[k] >= W) continue;
        if (s[i+dy[k]][j+dx[k]] == '#') {
          check = true;
          break;
        }
      }
      if (!check) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
