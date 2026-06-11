#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<P> cb(m);
  rep(i, m) {
    int b, c;
    cin >> b >> c;
    cb.at(i) = make_pair(c, b);
  }
  // ソート
  sort(a.begin(), a.end());
  sort(cb.rbegin(), cb.rend());
  int ai = 0;
  for (auto ccbb : cb) {
    rep(i, ccbb.second) {
      if (a.at(ai) < ccbb.first) {
        a.at(ai) = ccbb.first;
        ai++;
      } else {
        break;
      }
      if (ai >= n) {
        break;
      }
    }
    if (ai >= n) {
      break;
    }
  }

  ll res = 0;
  rep(i, n) {
    res += a.at(i);
  }
  cout << res << endl;
  return 0;
}
