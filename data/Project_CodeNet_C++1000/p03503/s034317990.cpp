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
  vector<int> f(n, 0);
  rep(i, n){
    int add = 0;
    int co = 1;
    rep(j, 10){
      int a;
      cin >> a;
      if(a == 1) add += co;
      co *= 2;
    }
    f.at(i) = add;
  }
  vector<vector<int>> p(n, vector<int>(11));
  rep(i, n){
    rep(j, 11){
      int a;
      cin >> a;
      p.at(i).at(j) = a;
    }
  }
  int ans = -1001001001;
  rep2(bit, 1, 1 << 10){
    int add = 0;
    rep(i, n){
      int co = 0;
      int now = bit & f.at(i);
      rep(bit2, 10){
        if((now & (1 << bit2)) != 0) co++;
      }
      add += p.at(i).at(co);
    }
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}