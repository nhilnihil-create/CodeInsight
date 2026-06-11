#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

int main(){
  ll N;
  cin>>N;
  ll C[N-1],S[N-1],F[N-1];
  for(ll i=0;i<N-1;i++){
    cin>>C[i]>>S[i]>>F[i];
  }
    ll ans=0;  
  for(ll i=0;i<N-1;i++){
	ans=0;
    for(ll j=i;j<N-1;j++){
      if(ans<=S[j]){ans=S[j];}
      else {ll start=(ll)(ans/(double)(F[j])+0.99999999);
           ans=start*F[j];
            //cout<<"start"<<start;
           }
      //cout<<"j"<<j<<"ans"<<ans<<" "<<C[j]<<endl;
      ans=ans+C[j];
      //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    
  }
  cout<<0<<endl;
  
}
