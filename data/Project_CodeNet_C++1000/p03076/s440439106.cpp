#include <bits/stdc++.h>
#define lol long long
template<class A,class B>inline bool chmax(A &a,const B &b){return(b>a&&(a=b,true));}
template<class A,class B>inline bool chmin(A &a,const B &b){return(b<a&&(a=b,true));}
using namespace std;
lol mod=1e9+7;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int ans=0;
  int sum=0;
  for(int i=0;i<5;i++){
    int a;cin >>a;
    ans+=10*(1+(a-1)/10);
    chmax(sum,10*(1+(a-1)/10)-a);
  }
  cout <<ans-sum<<'\n';
  return (0);
}