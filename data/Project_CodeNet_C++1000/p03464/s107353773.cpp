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
  int k;
  cin >> k;
  vector<int> a(k);
  rep(i, k) cin >> a.at(i);
  if(a.back() != 2){
    cout << -1 << endl;
    return 0;
  }
  ll mn = 2, mx = 2;
  rrep(i, k){
    int now = a.at(i);
    if(mn % now != 0 && mx < mn + (now - mn % now)){
      cout << -1 << endl;
      return 0;
    }
    mn = (mn + now - 1) / now * now;
    mx = (mx / now * now) + now - 1;
  }
  cout << mn << " " << mx << endl;
  return 0;
}