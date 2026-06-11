#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> vs(h, vector<char>(w));
  rep(j, h) {
    rep(i, w) {
      cin >> vs[j][i];
    }
  }

  vector<vector<char>> ans(h, vector<char>(w));
  rep(j, h) {
    rep(i, w) {
      if (vs[j][i] == '#') {
        ans[j][i] = '#';
        continue;
      }
      int count = 0;
      for (int y = j - 1; y <= j + 1; ++y) {
        for(int x = i - 1; x <= i + 1; ++x) {
          if (y < 0 || y >= h || x < 0 || x >= w) continue;
          if (vs[y][x] == '#') {
            count++;
          }
        }
      }
      ans[j][i] = '0' + count;
    }
  }

  rep(j, h) {
    rep(i, w) {
      cout << ans[j][i];
    }
    cout << endl;
  }
  
  return 0;
}