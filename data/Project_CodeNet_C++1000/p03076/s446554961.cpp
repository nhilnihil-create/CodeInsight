#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  vector<int> x(5);
  rep(i, 5) cin >> x.at(i);
  int res = INT_MAX;
  // 最後に注文するものを振る
  rep(i, 5) {
    int tmp = 0;
    rep(j, 5) {
      if (i == j) {
        tmp += x.at(j);
      } else {
        if (x.at(j) % 10 != 0) {
          tmp += (10 - x.at(j) % 10);
        }
        tmp += x.at(j);
      }
    }
    res = min(res, tmp);
  }
  cout << res << endl;
  return 0;
}
