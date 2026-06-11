#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n,m;
  cin>>n>>m;
  string s,t;
  cin>>s>>t;
  ll o=min(n,m);
  while(true){
    if(n%o==0&&m%o==0){
      break;
    }
    o--;
  }
  ll lcm=n*m/o;
  ll x=lcm/n,y=lcm/m;
  ll z=min(x,y);
  if(s.at(0)!=t.at(0)){
    cout<<-1<<endl;
    return 0;
  }
  else {
    while(true){
    if(x%z==0&&y%z==0){
      break;
    }
    z--;
  }
  ll lcm2=x*y/z;
  ll i=1;
  ll ans=0;
  while(lcm2*i<lcm){
    if(s.at(lcm2*i/x)==t.at(lcm2*i/y)){
      i++;
    }
    else{
         ans++;
         break;
    }
  }

    if(ans==0){
         cout<<lcm<<endl;
       }
    else{
         cout<<-1<<endl;
       }
  }
    
    
  
    
  
}
  
