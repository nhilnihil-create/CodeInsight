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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> lgcd(n), rgcd(n);
  lgcd.at(0) = a.at(0);
  rep2(i, 1, n){
    lgcd.at(i) = __gcd(a.at(i), lgcd.at(i-1));
  }
  rgcd.at(n-1) = a.back();
  rrep(i, n-1){
    rgcd.at(i) = __gcd(a.at(i), rgcd.at(i+1));
  }
  int ans = 0;
  rep(i, n){
    int add;
    if(i == 0){
      add = rgcd.at(i+1);
    }else if(i == n-1){
      add = lgcd.at(i-1);
    }else{
      add = __gcd(lgcd.at(i-1), rgcd.at(i+1));
    }
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}