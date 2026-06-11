#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  bool ok = true;
  vector<int> res;
  while (!b.empty()) {
    int cur = -1;
    per(i, b.size()) {
      if (b.at(i) == i + 1) {
        cur = i;
        break;
      }
    }
    if (cur == -1) {
      ok = false;
      break;
    } else {
      res.insert(res.begin(), b.at(cur));
      b.erase(b.begin() + cur);
    }
  }
  if (ok) {
    for (int c : res) {
      cout << c << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
