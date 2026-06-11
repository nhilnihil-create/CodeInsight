#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N,M;
  cin >> N >> M;
  vector<vector<ll>> S(M,vector<ll>(0));
  for(ll i=0;i<M;i++){
    ll k;
    cin >> k;
    vector<ll> t(k);
    for(ll j=0;j<k;j++){
      cin >> t[j];
    }
    S[i]=t;
  }
  vector<ll> P(M);
  for(ll i=0;i<M;i++){
    cin >> P[i];
  }
  ll ans=0;
  for(ll i=0;i<(1<<N);i++){
    bool TF=true;
    for(ll j=0;j<M;j++){
      ll count =0;
      for(ll m=0;m<S[j].size();m++){
        if(i & (1<<(S[j][m]-1))){
          count++;         
        }
      }
      if((count%2)!=P[j]){
        TF=false;
        break;
      }
    }
    if(TF){
      ans++;
    }
  }
  cout << ans <<  endl;
}