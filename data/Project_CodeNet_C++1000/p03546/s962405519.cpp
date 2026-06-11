#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<int>> c(10, vector<int>(10));
  rep(i, 10){
    rep(j, 10) cin >> c.at(i).at(j);
  }
  vector<int> a(10, 0);
  rep(i, h){
    rep(j, w){
      int in;
      cin >> in;
      if(in != -1) a.at(in)++;
    }
  }
  rep(k, 10){
    rep(i, 10){
      rep(j, 10){
        c.at(i).at(j) = min(c.at(i).at(j), c.at(i).at(k)+c.at(k).at(j));
      }
    }
  }
  ll ans = 0;
  rep(i, 10){
    ans += a.at(i) * c.at(i).at(1);
  }
  cout << ans << endl;
  return 0;
}