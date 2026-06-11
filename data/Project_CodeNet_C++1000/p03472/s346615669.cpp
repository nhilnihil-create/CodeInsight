#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  vector<int> b(n);
  int ma = 0;
  rep(i, n) {
    int aa, bb;
    cin >> aa >> bb;
    a.at(i) = aa;
    b.at(i) = bb;
    ma = max(ma, aa);
  }
  sort(b.rbegin(), b.rend());
  int bi = 0;
  int cnt = 0;
  while (h > 0) {
    if (bi != n && b.at(bi) > ma) {
      h -= b.at(bi);
      bi++;
      cnt++;
    } else {
      cnt += (h + ma - 1) / ma;
      h = 0;
      break;
    }
  }
  cout << cnt << endl;
  return 0;
}
