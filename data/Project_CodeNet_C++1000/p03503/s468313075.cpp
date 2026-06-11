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
  int n;
  cin >> n;
  vector<int> f(n);
  rep(i, n){
    int add = 0;
    rep(j, 10){
      int in;
      cin >> in;
      add <<= 1;
      if(in == 1)add++;
    }
    f.at(i) = add;
  }
  vector<vector<int>> p(n, vector<int>(11));
  rep(i, n){
    rep(j, 11){
      cin >> p.at(i).at(j);
    }
  }
  int ans = -2e9;
  rep2(bit, 1, 1 << 10){
    int add = 0;
    rep(i, n){
      int now = bit & f.at(i);
      auto fc = [] (int n)->int{
        int res = 0;
        while(n != 0){
          if(n % 2 == 1) res++;
          n /= 2;
        }
        return res;
      };
      int co = fc(now);
      add += p.at(i).at(co);
    }
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}