#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<(n);++i)

signed main(){

  int n;
  cin>>n;
  vector<ll> a(n);
  for(auto& ai:a)cin>>ai;

  ll cnt = 0;
  rep(i,n)if(a[i]<0)cnt++;

  for(auto&ai:a)ai=abs(ai);
  sort(begin(a),end(a));
  ll ans = accumulate(begin(a)+(cnt&1),end(a),(cnt&1?a[0]*-1ll:0ll));
  cout<<(ans)<<endl;

}