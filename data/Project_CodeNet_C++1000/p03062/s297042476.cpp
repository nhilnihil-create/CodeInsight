#include <bits/stdc++.h>
#define lol long long
template<class A,class B>inline bool chmax(A &a,const B &b){return(b>a&&(a=b,true));}
template<class A,class B>inline bool chmin(A &a,const B &b){return(b<a&&(a=b,true));}
using namespace std;
lol mod=1e9+7;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin >>n;
  vector<lol> a(n);
  for(int i=0;i<n;i++) cin >>a[i];
  int con=0,mi=mod;
  lol ans=0;
  for(int i=0;i<n;i++){
    if(a[i]<0) con++;
    chmin(mi,abs(a[i]));
    ans+=abs(a[i]);
  }
  cout <<ans-(con&1?(mi+mi):0)<<'\n';
  return (0);
}