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
  ll N,i,ans=0,SUM=0,B;cin>>N;
  V A(N);
  REP(i,N)cin>>A.at(i);
  REP(i,N){cin>>B;A.at(i)-=B;SUM+=A.at(i);}
  if(SUM>=0){
    sort(ALL(A));ll S=0;
    i=lower_bound(ALL(A),0)-A.begin();
    while(i<N){
      S+=A.at(i);i++;
      if(S<=SUM)ans++;
      else break;
    }
    ans=N-ans;
  }
  else ans=-1;
  cout<<ans<<endl;
  return 0;
}