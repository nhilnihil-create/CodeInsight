#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
#define VEC vector
#define V VEC<ll>
signed main(){
  ll N,M,G,i,ans=-1;string S,T;
  cin>>N>>M>>S>>T;G=__gcd(N,M);
  bool x=true;N/=G;M/=G;
  REP(i,G)if(S[i*N]!=T[i*M])x=false;
  if(x)ans=M*N*G;
  cout<<ans<<endl;
  return 0;
}