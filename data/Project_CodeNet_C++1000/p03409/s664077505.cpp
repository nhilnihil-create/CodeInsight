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
  ll N,i,j,ans=0;cin>>N;
  vector<P>BLUE(N),RED(N);
  REP(i,N)cin>>RED.at(i).S>>RED.at(i).F;
  REP(i,N)cin>>BLUE.at(i).F>>BLUE.at(i).S;
  sort(ALL(BLUE));sort(ALL(RED));reverse(ALL(RED));
  REP(i,N)REP(j,N)if(BLUE.at(i).F>RED.at(j).S&&BLUE.at(i).S>RED.at(j).F){
    RED.at(j)=P(2*N,2*N);ans++;break;
  }
  cout<<ans<<endl;
  return 0;
}