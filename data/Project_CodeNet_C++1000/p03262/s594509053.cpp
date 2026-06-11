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
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  rep(snip_i, n) cin >> v.at(snip_i);
  v.push_back(x);
  sort(v.begin(), v.end());
  int ans;
  rep(i, n){
    int d = v.at(i+1) - v.at(i);
    if(i == 0) ans = d;
    else ans = __gcd(ans, d);
  }
  cout << ans << endl;
  return 0;
}