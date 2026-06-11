#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll N,ans=0;
  cin>>N;
  vector<ll> h(N);
  for(ll i=0;i<N;i++){
    cin>>h.at(i);
    if(i==0){ans=h.at(i);}
    else if(h.at(i)>h.at(i-1)){ans+=h.at(i)-h.at(i-1);}
  }
  cout<<ans<<endl;
}