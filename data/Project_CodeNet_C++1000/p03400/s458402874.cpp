#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  ll res = x;
  rep(i, d) {
    rep(j, n) {
      int aa = a.at(j);
      if (i % aa == 0) {
        res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
