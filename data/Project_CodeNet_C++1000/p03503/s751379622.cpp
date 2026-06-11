#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define F first
#define S second
signed main(){
  ll N,i,j,k,ans=-1000000000;
  cin>>N;bool F[N][10];ll P[N][11];
  REP(i,N)REP(j,10)cin>>F[i][j];
  REP(i,N)REP(j,11)cin>>P[i][j];
  FOR(i,1,1024){
    bool X[10];ll c,rieki=0;
    REP(j,10)X[j]=((1<<j)&i)>0;
    REP(j,N){
      c=0;
      REP(k,10)if(X[k]&&F[j][k])c++;
      rieki+=P[j][c];
    }
    ans=max(ans,rieki);
  }
  cout<<ans<<endl;
  return 0;
}