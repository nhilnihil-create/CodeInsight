#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll n,a,m; cin>>n>>a;
  m=a;
  rep(i,5){
    cin>>a;
    if(a<m){m=a;}
  }
  ll ans=5;
  if(n%m==0){ans+=n/m-1;}
  else{ans+=n/m;}
  cout<<ans;
  
}