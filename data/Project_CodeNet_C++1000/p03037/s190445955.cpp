#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  int l = 1, r = n;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    if (l < x) l = x;
    if (y < r) r = y;
  }

  if (r - l < 0)
    cout << 0 << endl;
  else
    cout << r - l + 1 << endl;
  return 0;
}
