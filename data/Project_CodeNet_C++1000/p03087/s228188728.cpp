#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll N,Q;
  string S;
  cin>>N>>Q>>S;
  vector<ll> vec(N);
  for(ll i=0;i<N-1;i++){
    if(S.at(i)=='A' && S.at(i+1)=='C'){vec.at(i+1)=vec.at(i)+1;}
    else{vec.at(i+1)=vec.at(i);}
  }
  for(ll i=0;i<Q;i++){
    ll a,b;
    cin>>a>>b;
    cout<<vec.at(b-1)-vec.at(a-1)<<endl;
  }
}