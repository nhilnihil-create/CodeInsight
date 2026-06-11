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
  ll N,M,ans=1,i;cin>>N>>M;
  REP(i,M)ans*=2;
  cout<<(100*N+1800*M)*ans<<endl;
  return 0;
}