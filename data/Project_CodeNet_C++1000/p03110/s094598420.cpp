#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N;
  cin>>N;
  ll ans=0;
  double under=0;
  for(ll i=0;i<N;i++) {
    double x;
  string u;
    cin>>x>>u;
    
    if(u=="JPY") {
ans+=x;
    }
    else {
      ll a=x;
      ans+=a*380000;
      
      x-=a;
      x*=380000;
      ll b=x;
      ans+=x;
      under+=x-b;
    }
  }
  
  cout<<ans+under<<endl;
}

    
  
  
