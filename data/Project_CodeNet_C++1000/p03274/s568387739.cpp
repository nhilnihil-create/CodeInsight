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
  ll N,K,i,ans=1000000000;cin>>N>>K;ll x[N];
  REP(i,N)cin>>x[i];
  REP(i,N-K+1){
    ans=min(ans,min(abs(x[i]),abs(x[i+K-1]))+abs(x[i]-x[i+K-1]));
  }
  cout<<ans<<endl;
  return 0;
}