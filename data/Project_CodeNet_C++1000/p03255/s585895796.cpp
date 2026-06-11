#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1LL<<60);
ll N,X;

ll px[200005];
ll sx[200005];

int main(){
  cin>>N>>X;
  for(int i=0;i<N;i++){
    cin>>px[i];
    
    sx[i]=px[i];
    if(i)sx[i]+=sx[i-1];
    
  }
  
  ll ans=INF;
  for(int i=1;i<=N;i++){
    
    ll tmp=N*X+i*X;
    
    ll cc=0;
    for(int j=N-1;j>=0;j-=i){
      cc++;
      ll cx=5;
      if(cc>1)cx=2*cc+1;

      ll sum=sx[j];
      if(j-i>=0)sum-=sx[j-i];

      
      ll value = ( sum  < INF/cx ? sum*cx : INF );
      
      tmp += value;
      if( tmp > INF ) tmp = INF;
      
    }

    ans=min(ans,tmp);
  }
  cout<<ans<<endl;
  return 0;
}
