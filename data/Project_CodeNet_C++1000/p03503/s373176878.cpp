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
  int n;
  cin >> n;
  vector<int> f(n);
  rep(i, n){
    f.at(i) = 0;
    rep(j, 10){
      int in;
      cin >> in;
      f.at(i) *= 2;
      f.at(i) += in;
    }
  }
  vector<vector<int>> p(n, vector<int>(11));
  rep(i, n){
    rep(j, 11){
      int in;
      cin >> in;
      p.at(i).at(j) = in;
    }
  }

  int ans = -2e9;
  rep2(bit, 1, 1 << 10){
    int add = 0;
    rep(i, n){
      int c = __builtin_popcount(bit & f.at(i));
      add += p.at(i).at(c);
    }
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}