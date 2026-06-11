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
  vector<int> h(n);
  rep(snip_i, n) cin >> h.at(snip_i);
  sort(h.begin(), h.end());
  int ans = 1001001001;
  rep(i, n-k+1){
    int add = h.at(i+k-1) - h.at(i);
    ans = min(ans, add);
  }
  cout << ans << endl;
  return 0;
}