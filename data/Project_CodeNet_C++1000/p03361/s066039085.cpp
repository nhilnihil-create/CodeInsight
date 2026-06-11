#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> s[i][j];
    }
  }

  bool ok = true;

  rep(i, H) {
    rep(j, W) {
      if (s[i][j] == '#') {
        // 隣接する上下左右が#でないなら塗れない
        bool isBlack = false;
        if (i > 0) {
          isBlack = s[i - 1][j] == '#' ? true : isBlack;
        }
        if (i < H - 1) {
          isBlack = s[i + 1][j] == '#' ? true : isBlack;
        }
        if (j > 0) {
          isBlack = s[i][j - 1] == '#' ? true : isBlack;
        }
        if (j < W - 1) {
          isBlack = s[i][j + 1] == '#' ? true : isBlack;
        }
        if (!isBlack) {
          ok = false;
        }
      }
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}