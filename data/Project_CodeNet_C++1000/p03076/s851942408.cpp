#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  vector<ll>vec(5);
  ll b=10;
  for(ll i=0;i<5;i++){
    ll c;
    cin>>c;
    vec.at(i)=((c-1)/10+1)*10;
    if(c%10!=0){
    b=min(b,c%10);
    }
  }
  ll s=0;
  for(ll i=0;i<5;i++){
    s+=vec.at(i);
  }
  s-=10-b;
  cout<<s<<endl;
  return 0;
}
    
  


 
