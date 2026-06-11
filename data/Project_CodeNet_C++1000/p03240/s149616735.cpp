#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, t;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  rep(i, n) {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i] > 0) t = i;
  }

  rep(cx, 101) rep(cy, 101) {
    ll H = h[t] + abs(x[t] - cx) + abs(y[t] - cy);
    bool flag = true;
    rep(j, n) flag &= (h[j] == max(H - abs(x[j] - cx) - abs(y[j] - cy), 0LL));
    if (flag) {
      cout << cx << " " << cy << " " << H << endl;
      return 0;
    }
  }
  return 0;
}
