#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int k = 50;
  string grid[100];
  for (int i = 0; i < 2 * k; i++) {
    for (int j = 0; j < 2 * k; j++) {
      if (i < k)
        grid[i] += '.';
      else
        grid[i] += '#';
    }
  }
  a--;
  b--;
  for (int i = 0; i < 50; i += 2) {
    for (int j = 0; j < 100; j += 2) {
      if (b > 0) {
        grid[i][j] = '#';
        b--;
      }
    }
  }
  for (int i = 51; i < 100; i += 2) {
    for (int j = 0; j < 100; j += 2) {
      if (a > 0) {
        grid[i][j] = '.';
        a--;
      }
    }
  }
  cout << 100 << " " << 100 << '\n';
  for (auto s : grid)
    cout << s << '\n';
  return 0;
}
