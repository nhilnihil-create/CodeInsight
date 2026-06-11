#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  int a[n], b[n];
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  int ans = 0;
  rep(i,29) {
    int c = 1 << i;
    vector<int> ad(n), bd(n);
    rep(j,n) {
      ad[j] = a[j] % (c*2);
      bd[j] = b[j] % (c*2);
    }
    sort(bd.begin(),bd.end());
    int num = 0;
    rep(j,n) {
      num += lower_bound(bd.begin(),bd.end(),2*c-ad[j]) - lower_bound(bd.begin(),bd.end(),c-ad[j]);
      num += lower_bound(bd.begin(),bd.end(),4*c-ad[j]) - lower_bound(bd.begin(),bd.end(),3*c-ad[j]);
    }
    if(num % 2) ans += c;
  }
  cout << ans << endl;
  return 0;
}