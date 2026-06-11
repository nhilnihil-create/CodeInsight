#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define repr(i,n) for(int i{n};i-->0;)

signed main(){

  ll n,z,w;
  cin>>n>>z>>w;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  if(n==1){
    cout<<abs(a[0]-w)<<endl;
  }else{
    cout<<max(abs(a.back()-w),abs(a[n-1]-a[n-2]))<<endl;
  }

}