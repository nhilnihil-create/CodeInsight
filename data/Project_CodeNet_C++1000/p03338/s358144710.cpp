#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<char> a(n);
  rep(i,n) cin >> a[i];
  int ans = 0;
  rep(i,n) {
    vector<bool> aa(26,false), bb(26,false);
    rep(j,i) aa[a[j]-'a']=true;
    for(int k = n-1; k >= i; k--) bb[a[k]-'a']=true;
    int cnt = 0;
    rep(m,26) {
      if(aa[m]&&bb[m]) cnt++;
    }
    ans = max(ans,cnt);
  }  
  cout << ans << endl;
  return 0;
}