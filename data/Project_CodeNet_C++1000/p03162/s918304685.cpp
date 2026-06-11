#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (i == 0) {
      x = a, y = b, z = c;
    } else {
      int nx = max(y + a, z + a);
      int ny = max(x + b, z + b);
      int nz = max(x + c, y + c);
      x = nx;
      y = ny;
      z = nz;
    }
  }
  cout << max(x, max(y, z)) << endl;
}
