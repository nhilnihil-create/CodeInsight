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
  ll N,i,x,y,h,m;cin>>N;
  ll X[N],Y[N],H[N],D[N];
  REP(i,N)cin>>X[i]>>Y[i]>>H[i];
  REP(x,101){
    REP(y,101){
      h=-1;m=10000100000;
      REP(i,N)D[i]=abs(X[i]-x)+abs(Y[i]-y);
      REP(i,N){
        if(H[i]==0)m=min(m,D[i]);
        else if(h==-1)h=H[i]+D[i];
        else if(h!=H[i]+D[i]){h=m+1;break;}
      }
      if(h<=m)break;
    }
    if(y<101)break;
  }
  cout<<x<<" "<<y<<" "<<h<<endl;
  return 0;
}