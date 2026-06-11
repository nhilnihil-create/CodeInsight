#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
using namespace std;
using ll=long long;

ll count5(ll a, ll b, ll c, ll d, ll e){
  ll ans=0;
  ans+=a*b*c;
  ans+=a*b*d;
  ans+=a*b*e;
  ans+=a*c*d;
  ans+=a*c*e;
  ans+=a*d*e;
  ans+=b*c*d;
  ans+=b*c*e;
  ans+=b*d*e;
  ans+=c*d*e;
  return ans;
}

int main(){
  ll N; cin>>N;
  vector<ll> M(5);
  vector<ll> count(5);
  for(int i=0; i<N; i++){
    string s; cin>>s;
    if(s[0]=='M'){
      M[0]++;
      if(count[0]==0) count[0]++;
    }
    if(s[0]=='A'){
      M[1]++;
      if(count[1]==0) count[1]++;
    }
    if(s[0]=='R'){
      M[2]++;
      if(count[2]==0) count[2]++;
    }
    if(s[0]=='C'){
      M[3]++;
      if(count[3]==0) count[3]++;
    }
    if(s[0]=='H'){
      M[4]++;
      if(count[4]==0) count[4]++;
    }
  } //s
  ll sum=0;
  for(int i=0; i<5; i++) sum+=count[i];
  if(sum<3) cout<<0<<endl;
  if(sum==3){
    ll ans=1;
    for(int i=0; i<5; i++){
      if(count[i]!=0) ans*=M[i];
    }
    cout<<ans<<endl;
  }
  if(sum==4){
    ll sum=1;
    for(int i=0; i<5; i++){
      if(count[i]!=0) sum*=M[i];
    }
    ll ans=0;
    for(int i=0; i<5; i++){
      if(count[i]!=0) ans+=sum/M[i];
    }
    cout<<ans<<endl;
  }
  if(sum==5){
    ll ans=count5(M[0], M[1], M[2], M[3], M[4]);
    cout<<ans<<endl;
  }
}