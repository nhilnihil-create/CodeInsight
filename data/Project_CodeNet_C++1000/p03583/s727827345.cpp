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
  ll n;
  cin >> n;
  rep2(i, 1, 3501){
    rep2(j, i, 3501){
      double nij = n*i*j;
      double bo = 4*i*j - n*i - n*j;
      if(bo == 0) continue;
      double k = nij/bo;
      if(floor(k) == k && k > 0){
        cout << i << " " << j << " " << (ll)k << endl;
        return 0;
      }
    }
  }
  return 1;
}