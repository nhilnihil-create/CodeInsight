#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(snip_i, n) cin >> a.at(snip_i);
  vector<int> b(n);
  rep(snip_i, n) cin >> b.at(snip_i);
  int ans = 0;
  ll mi = 0;
  vector<ll> pl;
  rep(i, n){
    int diff = a.at(i) - b.at(i);
    if(diff > 0) pl.push_back(diff);
    else if(diff < 0){
      mi += diff;
      ans++;
    }
  }
  // cerr << mi << endl;
  // cerr << "t" << ans << endl;
  sort(pl.rbegin(), pl.rend());
  for(int i : pl){
    if(mi >= 0) break;
    mi += i;
    ans++;
  }
  if(mi < 0){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }

  return 0;
}