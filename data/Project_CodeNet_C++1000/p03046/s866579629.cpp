#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int main() {
  int m, k;
  cin >> m >> k;
  if (k >= pow(2, m)) {
    cout << -1 << endl;
    return 0;
  }
  if (m == 0) {
    if (k == 0) {
      cout << 0 << endl << 0 << endl;
      return 0;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  if (m == 1) {
    if (k == 0) {
      cout << 0 << endl << 0 << endl << 1 << endl << 1 << endl;
      return 0;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> l(pow(2, m) - 1);
  vector<int> r(pow(2, m) - 1);
  vector<int> ans(pow(2, m + 1));
  int id = 0;
  rep(i, pow(2, m)) {
    if (i == k) continue;
    l[id] = i;
    id++;
  }
  id = 0;
  rep(i, pow(2, m)) {
    if (pow(2, m) - 1 - i == k) continue;
    r[id] = pow(2, m) - 1 - i;
    id++;
  }
  rep(i, pow(2, m) - 1) ans[i] = l[i];
  ans[pow(2, m) - 1] = k;
  rep(i, pow(2, m) - 1) ans[i + pow(2, m)] = r[i];
  ans[pow(2, m + 1) - 1] = k;
  rep(i, pow(2, m + 1)) cout << ans[i] << endl;
  return 0;
}