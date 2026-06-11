#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,L,R) for(i=L;i<R;i++)
#define REP(i,N) FOR(i,0,N)
int main(){
  ll N,A,B,C,ans=1000000000,s=1,i;cin>>N>>A>>B>>C;ll L[N];
  REP(i,N){s*=4;cin>>L[i];}
  REP(i,s){
    ll p=i,j,d[4]={0,0,0,0},c[4]={0,0,0,0};
    REP(j,N){d[p%4]+=L[j];c[p%4]++;p/=4;}
    if(c[0]&&c[1]&&c[2])ans=min(ans,abs(d[0]-A)+abs(d[1]-B)+abs(d[2]-C)+10*(c[0]+c[1]+c[2])-30);
  }
  cout<<ans<<endl;
}