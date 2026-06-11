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
  vector<pair<int, int>> ans;
  rep(i, n){
    rep2(j, i+1, n){
      int ii = i+1, jj = j+1;
      if(n % 2 == 0){
        if(ii + jj == n+1) continue;
      }else{
        if(ii + jj == n) continue;
      }
      ans.push_back(make_pair(ii, jj));
    }
  }
  cout << ans.size() << endl;
  for(auto p : ans){
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}