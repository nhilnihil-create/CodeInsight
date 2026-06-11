#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
  int n; cin >>n;
  vector<int> a(n), b(n), c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  vector<int> bc(n);
  rep(i,n) {
    int bi = b[i];
    auto ub = upper_bound(c.begin(), c.end(), bi);
    bc[i] = distance(ub, c.end());
  }

  vector<ll> bcc(n);
  bcc[n-1] = bc[n-1];
  for(int i=n-2; i>=0; i--) bcc[i] = bcc[i+1] + bc[i];
  
  ll ans = 0;
  rep(i,n) {
    int ai = a[i];
    auto ub = upper_bound(b.begin(), b.end(), ai);
    if(ub==b.end()) continue;
    int j = distance(b.begin(), ub);
    ans +=  bcc[j];
  }
  cout << ans << endl;
}
