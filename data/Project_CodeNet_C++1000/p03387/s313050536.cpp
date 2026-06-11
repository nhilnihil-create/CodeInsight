#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  vector<int> a(3);
  rep(snip_i, 3) cin >> a.at(snip_i);
  sort(ALL(a));
  int ans = a.at(2) - a.at(1);
  a.at(0) += ans;
  int d = a.at(2) - a.at(0);
  // cerr << ans << d << endl;
  if(d % 2 == 0) ans += d/2;
  else ans += (d+1)/2+1;
  cout << ans << endl;
  return 0;
}