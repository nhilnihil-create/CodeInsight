#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  for (auto&& e : grid) {
    cin >> e;
  }

  string res = "Yes";
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == '#') {
        bool b1 = i > 0 && grid[i - 1][j] == '#';
        bool b2 = j > 0 && grid[i][j - 1] == '#';
        bool b3 = i + 1 < h && grid[i + 1][j] == '#';
        bool b4 = j + 1 < w && grid[i][j + 1] == '#';
        if (!(b1 || b2 || b3 || b4)) {
          res = "No";
        }
      }
    }
  }

  cout << res << endl;
}
