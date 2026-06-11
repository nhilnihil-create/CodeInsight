#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> l(q), r(q);
  rep(i, q) {
    cin >> l[i] >> r[i];
    --l[i];
    --r[i];
  }
  vector<int> cum(n);
  cum[0] = 0;
  for (int i = 1; i < n; ++i) {
    cum[i] = cum[i-1];
    if (s[i-1] == 'A' && s[i] == 'C') ++cum[i];
  }

  rep(qi, q) {
    int ans = cum[r[qi]] - cum[l[qi]];
    cout << ans << endl;
  }

  return 0;
}