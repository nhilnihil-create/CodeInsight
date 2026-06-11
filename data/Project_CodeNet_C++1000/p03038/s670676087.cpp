#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N,M;
  cin >> N >> M;
  vector<pair<ll,ll>> a;
  for(ll i=0;i<N;i++){
    ll x;
    cin >> x;
    a.push_back( make_pair(x,1) );
  }
  for(ll i=0;i<M;i++){
    ll b,c;
    cin >> b >> c;
    a.push_back( make_pair(c,b) );
  }
  
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  
  ll cnt=0;
  vector<ll> res;
  for(auto p : a){
    ll b,c;
    tie(b,c) = p;
    for(int i=0;i<c;i++){
      res.push_back(b);
    }
    if(res.size() >= N){
      break;
    }
  }
  
  ll sum=0;
  for(ll i=0;i<N;i++){
    sum += res.at(i);
  }
  
  cout << sum << endl;
  
  return(0);
}