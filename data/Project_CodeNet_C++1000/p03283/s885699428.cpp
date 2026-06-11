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
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> imos(n, vector<int>(n, 0));
  vector<vector<int>> sums(n, vector<int>(n+1, 0));
  rep(i, m){
    int l, r;
    cin >> l >> r;
    l--; r--;
    imos.at(l).at(r)++;
  }
  rep(i, n){
    rep(j, n){
      sums.at(i).at(j+1) = sums.at(i).at(j) + imos.at(i).at(j);
    }
  }

  rep(_q, q){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    rep2(i, a-1, b){
      ans += sums.at(i).at(b) - sums.at(i).at(a-1);
    }
    cout << ans << endl;
  }
  return 0;
}