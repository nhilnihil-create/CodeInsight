#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;

signed main(){

  i64 n,k;
  cin>>n>>k;
  vector<i64> a(n);
  for(auto& ai:a)cin>>ai;

  i64 res = 0;
  for(int i=62;i>=0;--i){
    if((res|(1LL<<i))>k)continue;
    int cnt = 0;
    for(auto& ai:a)cnt+=((ai>>i)&1);
    if(cnt<=n/2)res|=(1LL<<i);
  }
  i64 ans = 0;
  for(auto& ai:a)ans+=ai^res;
  cout<<(ans)<<endl;

}