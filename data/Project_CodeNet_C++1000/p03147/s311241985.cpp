#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 100;
vector<ll> h(MAX_N);

int rec(int hh, int l, int r) {
  int res = 0;
  int nl = l, nr;
  bool flag = (h[l] >= hh + 1);
  for (int i = l; i < r; i++) {
    // cerr << "log: " << flag << " " << i << endl;
    if (flag && h[i] < hh + 1) {
      nr = i;
      flag = !flag;
      // cerr << hh + 1 << " " << nl << " " << nr << endl;
      res += 1 + rec(hh + 1, nl, nr);
    } else if (!flag && h[i] >= hh + 1) {
      nl = i;
      flag = !flag;
    }
  }
  if (flag) {
    nr = r;
    res += 1 + rec(hh + 1, nl, nr);
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  rep(i, n) cin >> h[i];
  // rep(i, n) cerr << h[i] << " ";
  // cerr << endl;
  cout << rec(0, 0, n) << endl;
  return 0;
}
