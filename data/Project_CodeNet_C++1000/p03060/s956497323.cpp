#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
  int n;
  cin >> n;
  vector<int> v(n), c(n);
  rep(i,n) cin >> v[i];
  rep(i,n) cin >> c[i];

  int ans = 0;
  rep(b, 1<<n) {
    int s = 0;
    rep(i,n)  if(b&1<<i) {
      s += v[i] - c[i];
    }
    ans = max(ans, s);
  }
  cout << ans << endl;
}
