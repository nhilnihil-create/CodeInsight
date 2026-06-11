#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  rep(i, n) {
    int xi;
    cin >> xi;
    x = max(x, xi);
  }
  rep(i, m) {
    int yi;
    cin >> yi;
    y = min(y, yi);
  }

  for (int z = -100; z <= 100; ++z) {
    if (x < z && z <= y) {
      cout << "No War" << endl;
      return 0;
    }
  }

  cout << "War" << endl;
  return 0;
}
