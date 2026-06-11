#include <bits/stdc++.h>
#define lol long long
template<class A,class B>inline bool chmax(A &a,const B &b){return(b>a&&(a=b,true));}
template<class A,class B>inline bool chmin(A &a,const B &b){return(b<a&&(a=b,true));}
using namespace std;
lol mod=1e9+7;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >>n;
  int ans=0;
  vector<int> x(n),y(n);
  for(auto&&e:x) cin >>e;
  for(auto&&e:y) cin >>e;
  while(n--){
    if(x[n]-y[n]>0) ans+=x[n]-y[n];
  }
  cout <<ans<<'\n';
  return (0);
}