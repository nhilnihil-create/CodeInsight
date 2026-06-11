#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  cin>>a;
  ll b=0;
  for(ll i=0;i<a;i++){
    ll c;
    cin>>c;
    for(ll j=0;;){
      if(c%2==0){
        c=c/2;
        j++;
      }
      else{
        b+=j;
        break;
      }
    }    
  }
  cout<<b<<endl;
  return 0;
}
