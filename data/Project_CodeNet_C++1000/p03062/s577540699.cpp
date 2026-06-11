#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int mn = 1e9;
  int mni = -1;
  rep(i,n) {
    if(mn > abs(a[i])) {
      mn = abs(a[i]);
      mni = i;
    }
  }
  rep(i, mni) {
    if(a[i] < 0) {
      a[i] *= -1;
      a[i+1] *= -1;
    }
  }
  for(int i=n-1; i> mni; i--) {
    if(a[i] < 0) {
      a[i] *= -1;
      a[i-1] *= -1;
    }
  }
  ll ans = 0;
  rep(i,n) ans += a[i];
  cout << ans << endl;
}
