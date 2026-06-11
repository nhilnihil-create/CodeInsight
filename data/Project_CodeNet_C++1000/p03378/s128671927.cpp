#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(m);
  rep(i, m) cin >> a.at(i);
  vector<int> s(n + 1, 0);
  rep(i, n + 1) {
    int cost = 0;
    if (find(a.begin(), a.end(), i) != a.end()) {
      cost = 1;
    }
    if (i == 0) {
      s.at(i) = cost;
    } else {
      s.at(i) = s.at(i - 1) + cost;
    }
  }
  int res = min(s.at(n) - s.at(x), s.at(x) - s.at(0));
  cout << res << endl;

  return 0;
}
