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
  ll N,i,j;cin>>N;ll C[N-1],S[N-1],F[N-1];
  REP(i,N-1)cin>>C[i]>>S[i]>>F[i];
  REP(i,N){
    ll T=0;
    FOR(j,i,N-1)T=(max(T,S[j])+F[j]-1)/F[j]*F[j]+C[j];
    cout<<T<<endl;
  }
  return 0;
}