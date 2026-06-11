#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll x,y,z,k;
  cin>>x>>y>>z>>k;
  
  vector<ll> A(x),B(y),C(z);
  rep(i,x) cin>>A[i];
  rep(i,y) cin>>B[i];
  rep(i,z) cin>>C[i];
  
  vector<ll> D,E;
  rep(i,x){
    rep(j,y) D.push_back(A[i]+B[j]);
  }
  
  sort(ALL(D),greater<ll>());
  sort(ALL(C),greater<ll>());

  rep(i,min(k,x*y)){
    rep(j,z) E.push_back(D[i]+C[j]);
  }
  
  sort(ALL(E),greater<ll>());
  
  rep(i,k) cout<<E[i]<<endl;
    
  return 0;
}