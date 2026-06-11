#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N; cin>>N;
  vector<ll> X(N);
  vector<ll> Y(N);
  for(ll i=0; i<N; i++){
    ll A; cin>>A;
    X[i]=A;
    Y[i]=A;
  }
  sort(X.begin(), X.end());
  ll M1=X[N/2];
  ll M2=X[(N/2)-1];
  for(ll i=0; i<N; i++){
    if(Y[i]<M1) cout<<M1<<endl;
    else cout<<M2<<endl;
  }
}
