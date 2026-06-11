#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int vx[] = {-1, 1, 0, 0};
const int vy[] = {0, 0, -1, 1};

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> g(h + 2, vector<char>(w + 2, '.'));

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> g[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (g[i][j] == '.') continue;

      bool ok = false;
      for (int k = 0; k < 4; k++) {
        if (g[i + vy[k]][j + vx[k]] == '#') ok = true;
      }
      if (!ok) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
}
