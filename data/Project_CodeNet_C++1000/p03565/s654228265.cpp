#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string sd, t;
  cin >> sd >> t;
  string res(sd);
  bool hit = false;
  for (int i = sd.size() - t.size(); i >= 0; i--) {
    bool ok = true;
    for (int j = 0; j < t.size(); j++) {
      if (sd.at(i + j) != t.at(j) && sd.at(i + j) != '?') {
        ok = false;
        break;
      }
    }
    if (ok) {
      for (int j = 0; j < t.size(); j++) {
        res.at(i + j) = t.at(j);
      }
      hit = true;
      break;
    }
  }
  if (hit) {
    // 残りの ? はすべて a に置換
    replace(res.begin(), res.end(), '?', 'a');
    cout << res << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
  return 0;
}
