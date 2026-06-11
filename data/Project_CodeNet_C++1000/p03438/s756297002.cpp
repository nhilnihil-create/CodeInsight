#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,asum=0,bsum=0;cin>>n;
  lvector A(n,0),B(n,0);
  rep(i,n) {cin>>A[i]; asum+=A[i];}
  rep(i,n) {cin>>B[i]; bsum+=B[i];}
  ll sdiff=bsum-asum;
  if(sdiff<0) {print("No"); return 0;}
  else if(sdiff==0) {
    bool isok=true;
    rep(i,n) if(A[i]!=B[i]) {isok=false;break;}
    if(isok) puts("Yes");else puts("No");
  }
  else {
    ll val1=0,val2=0;
    rep(i,n) {
      if(A[i]<B[i]) val1+=(B[i]-A[i]+1)/2;
      if(A[i]>B[i]) val2+=A[i]-B[i];
    }
    if(max(val1,val2)>sdiff) puts("No");else puts("Yes");
  }
  return 0;
}