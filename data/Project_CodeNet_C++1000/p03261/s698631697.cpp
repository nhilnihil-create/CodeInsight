#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
const ll INF = 1LL<<60;

int main(){
  ll N;
  cin>>N;
  string W[N];
  ll ans=0;
  rep(i,N){
   cin>>W[i];
  }
  rep(i,N-1){
   if(W[i][(int)W[i].size()-1]!=W[i+1][0]){ans=1;}
  }
  rep(i,N-1){
    for(int j=i+1;j<N;j++){
    if(W[i]==W[j]){ans=1;}
    }
  }
  if(ans==1){
cout<<"No"<<endl;}
  else{cout<<"Yes"<<endl;}
}
