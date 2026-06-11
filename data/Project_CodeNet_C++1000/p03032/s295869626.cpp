#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int fc(vector<int> &v,int k, int lc, int rc){
  if(k < lc + rc) return -1e9;
  int n = v.size();
  vector<bool> chk(n, false);
  vector<int> now;
  rep(i, lc){
    now.push_back(v.at(i));
    k--;
    chk.at(i) = true;
  }
  rep(i, rc){
    if(chk.at(n-i-1) == false){
      k--;
      now.push_back(v.at(n-i-1));
    }else break;
  }
  
  sort(now.begin(), now.end());
  int ret = accumulate(now.begin(), now.end(), 0);
  rep(i, k){
    if(i >= now.size() || now.at(i) >= 0) break;
    ret -= now.at(i);
  }
  // cerr << ret << endl;
  return ret;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(snip_i, n) cin >> v.at(snip_i);
  int ans = -1e9-5;
  rep(i, n+1){
    rep(j, n+1){
      // cerr << i << " " << j << " " << ans << endl;
      ans = max(ans, fc(v, k, i, j));
    }
  }
  cout << ans << endl;

  return 0;
}