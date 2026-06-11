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
  rep(i, n){
    bool f = false;
    if(i == 0){
      if(a.at(i) != 0) f = true;
    }else{
      if(a.at(i) - a.at(i-1) > 1) f = true;
    }
    if(f == true){
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> ans(n);
  rep(i, n){
    ans.at(i) = i - a.at(i);
  }

  ll aa = 0;
  rrep(i, n){
    if(i == n-1 || ans.at(i) != ans.at(i+1)){
      aa += i - ans.at(i);
    }
  }
  cout << aa << endl;
  return 0;
}