#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

int main(){
  ll N;
  cin>>N;
  ll F[N+1][10+1];
  for(ll k=1;k<N+1;k++){
	  for(ll i=1;i<10+1;i++){
  	cin>>F[k][i];
  	}
  }
  ll P[N+1][10+1];
  for(ll j=1;j<N+1;j++){
  for(ll i=0;i<10+1;i++){
  	cin>>P[j][i];
  }
  }
  
ll ans=-INF;
  for(ll i=1;i<1024;i++){
    ll counter[N+1]={0};
    ll house[10+1]={0};
    ll inum=i;
    for(ll j=1;j<10+1;j++){
      house[j]=inum%2;
      inum=inum/2;
      if(house[j]==1){
        for(ll k=1;k<N+1;k++){counter[k]=counter[k]+F[k][j];}
      }
    }
    ll lans=0;
    for(ll m=1;m<N+1;m++){
      lans=lans+P[m][counter[m]];
    }
    if(lans>ans){
    ans=lans;
    }
    
  }
  
  cout<<ans<<endl;
}
