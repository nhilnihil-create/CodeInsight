#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;

int main() {
  cin >> n;
  vector<vector<char>> a(n, vector<char>(n));
  range(i, 0, n) {
    range(j, 0, n) cin >> a[i][j];
  }
  int res = 0;
  range(dif, 1 - n, n) {
    bool ok = true;
    range(x, 0, n) {
      range(y, 0, n) {
        // sx - sy + x - y = 2 * dif
        // sx + sy = x + y
        // sx = y + dif
        // sy = x - dif
        int sx = ((y + dif) % n + n) % n;
        int sy = ((x - dif) % n + n) % n;
        ok &= a[x][y] == a[sx][sy];
      }
    }
    if(ok) {
      int s = abs(dif);
      // x - y = dif
      // x >= dif x < n
      res += n - s;
    }
  }
  cout << res;
  return 0;
}
