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
  ll N,i,B,pos=0,neg=0;cin>>N;ll A[N];
  REP(i,N)cin>>A[i];
  REP(i,N){
    cin>>B;A[i]-=B;
    if(A[i]>0)pos+=A[i];
    else neg+=-A[i]/2;
  }
  if(pos<=neg)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}