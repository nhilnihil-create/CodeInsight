#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int res = 0;
  for (int i = 0; i <= n / r; i++) {
    for (int j = 0; j <= n / g; j++) {
      int sum = i * r + j * g;
      if (sum > n) {
        continue;
      }
      if ((n - sum) % b == 0) {
        res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
