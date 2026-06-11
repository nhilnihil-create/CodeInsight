#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  int lr = 0, rr = n;
  vector<int> l(m), r(m);
  rep(i,m) {
    cin >> l[i] >> r[i];
    lr = max(lr, l[i]);
    rr = min(rr, r[i]);
  }
  int ans = rr - lr + 1;
  if (ans <= 0) ans = 0;
  cout << ans << endl;
  return 0;
}