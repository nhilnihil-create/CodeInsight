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
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(snip_i, n) cin >> x.at(snip_i);
  int ans = 1001001001;
  rep(i, n-k+1){
    int l = x.at(i), r = x.at(i+k-1);
    int add1 = abs(r) + abs(r-l);
    int add2 = abs(l) + abs(l-r);
    int add = min(add1, add2);
    ans = min(ans, add);
  }
  cout << ans << endl;
  return 0;
}