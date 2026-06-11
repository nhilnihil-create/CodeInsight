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
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> vp(m);
  vector<vector<int>> co(n, vector<int>(n, 0));
  rep(i, m){
    int l, r;
    cin >> l >> r;
    l--; r--;
    co.at(l).at(r)++;
  }
  vector<vector<int>> sum(n, vector<int>(n+1, 0));

  rep(i, n){
    rep(j, n){
      sum.at(i).at(j+1) = sum.at(i).at(j) + co.at(i).at(j);
    }
  }


  // rep(i, n){
  //   rep(j, n+1){
  //     cout << sum.at(i).at(j) << " ";
  //   }
  //   cout << endl;
  // }
  
  rep(__, q){
    int l, r;
    cin >> l >> r;
    int ans = 0;
    rep2(i, l-1, r){
      ans += sum.at(i).at(r) - sum.at(i).at(l-1);
    }
    cout << ans << endl;
  }
  return 0;
}