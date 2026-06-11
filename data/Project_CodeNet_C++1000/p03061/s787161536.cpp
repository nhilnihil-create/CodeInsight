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
  vector<int> fro(n),bak(n);
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >>a[i];
  fro[0]=a[0];
  bak.back()=a.back();
  for(int i=1;i<n;i++){
    fro[i]=gcd(fro[i-1],a[i]);
  }
  for(int i=n-2;i>=0;i--){
    bak[i]=gcd(bak[i+1],a[i]);
  }
  int ans=0;
  for(int i=1;i<n-1;i++){
    chmax(ans,gcd(fro[i-1],bak[i+1]));
  }
  chmax(ans,bak[1]);
  chmax(ans,fro[n-2]);
  cout <<ans<<'\n';
  return (0);
}