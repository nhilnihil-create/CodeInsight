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
  ll pl2 = 0, mi = 0;
  rep(i, n){
    int diff = b.at(i) - a.at(i);
    if(diff < 0) mi += diff;
    if(diff >= 2) pl2 += diff/2;
  }
  if(pl2 + mi >= 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}