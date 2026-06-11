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
  ll n;
  cin >> n;
  rep2(i, 1, 3501){
    rep2(j, 1, 3501){
      double d = (double)n*i*j / (double)(4*i*j-n*(i+j));
      int k = d;
      if(k != d || k < 0 || k > 3500) continue;
      cout << i << " " << j << " " << k << endl;
      return 0;
    }
  }
  return 0;
}