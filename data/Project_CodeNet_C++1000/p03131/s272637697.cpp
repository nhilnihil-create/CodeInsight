#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
#define V vector
signed main(){
  ll K,A,B,ans;cin>>K>>A>>B;
  if(B-1<=A||A-1>=K)ans=K+1;
  else ans=(K-A+1)/2*(B-A)+(K-A+1)%2+A;
  cout<<ans<<endl;
  return 0;
}