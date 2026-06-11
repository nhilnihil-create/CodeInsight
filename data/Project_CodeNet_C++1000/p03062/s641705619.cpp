#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll n; cin>>n;
  vector<ll> v(n);
  ll sum=0, cm=0, m;
  rep(i,n){
    cin>>v[i];
    if(i==0){m=abs(v[0]);}
    sum+=abs(v[i]);
    if(v[i]<0){cm++;}
    m=min(m,abs(v[i]));
  }
  if(cm %2==0 || m==0){cout<<sum;}
  else{cout<<sum-2*m;}
}

