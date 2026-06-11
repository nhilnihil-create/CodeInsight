#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  // rep(i,n) cout << a[i] << endl;
  vector<pair<ll,ll>> bc(0);
  ll b,c;
  rep(i,m) {
    cin >> b >> c;
    bc.push_back({c,b});
  }
  sort(bc.begin(),bc.end());
  // rep(i,m) cout << bc[i].first << bc[i].second << endl;
  ll ans = 0;
  int nMax = n-1;
  rep(i,n) {
    if (m == 0) {
      ans += a[nMax];
      nMax--;
    }
    else if (a[nMax] > bc[m-1].first) {
      ans += a[nMax];
      nMax--;
    }
    else {
      ans += bc[m-1].first;
      bc[m-1].second--;
      if (bc[m-1].second == 0) {
        m--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
