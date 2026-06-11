#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,i,ans=0;cin>>N;ll A[N],R[N],L[N];
  REP(i,N)cin>>A[i];R[0]=0;L[0]=0;
  REP(i,N-1){
    R[i+1]=__gcd(R[i],A[i]);
    L[i+1]=__gcd(L[i],A[N-i-1]);
  }
  REP(i,N)ans=max(ans,__gcd(R[i],L[N-1-i]));
  cout<<ans<<endl;
  return 0;
}