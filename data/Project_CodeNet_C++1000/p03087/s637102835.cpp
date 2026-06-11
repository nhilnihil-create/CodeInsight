#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
int main(){
  ll N,Q;
  string S;
  cin>>N>>Q>>S;
  vector<ll> vec(N);
  vector<ll> vec2(N);
  for(ll i=0;i<N-1;i++){
    if(S.at(i)=='A' && S.at(i+1)=='C'){
      if(i==0){vec.at(i)=1;}
      if(i!=0){vec.at(i)=vec.at(i-1)+1;}
    }
    else{
      if(i==0){vec.at(i)=0;}
      else{vec.at(i)=vec.at(i-1);}
    }
  }
  vec.at(N-1)=vec.at(N-2);
  for(ll i=0;i<N-1;i++){
    if(S.at(i)=='A' && S.at(i+1)=='C'){
      if(i==0){vec2.at(i+1)=1;}
      if(i!=0){vec2.at(i+1)=vec2.at(i)+1;}
    }
    else{
      if(i==0){vec2.at(i+1)=0;}
      else{vec2.at(i+1)=vec2.at(i);}
    }
  }
  vec2.at(0)=0;
  for(ll i=0;i<Q;i++){
    ll a,b;
    cin>>a>>b;
    cout<<vec2.at(b-1)-vec2.at(a-1)<<endl;
  }
}