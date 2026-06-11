#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int vx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int vy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> m(h + 2, vector<char>(w + 2, '.'));
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) cin >> m[i][j];
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (m[i][j] == '#') {
        cout << '#';
        continue;
      }

      int count = 0;
      for (int k = 0; k < 8; k++) {
        if (m[i + vy[k]][j + vx[k]] == '#') count++;
      }
      cout << count;
    }
    cout << endl;
  }
}
