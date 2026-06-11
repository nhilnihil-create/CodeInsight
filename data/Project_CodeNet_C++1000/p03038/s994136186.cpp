#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N,M;
  cin  >> N >>M;
  vector<pair<ll,ll>> T;
  for(ll i=0;i<N;i++){
    ll a;
    cin >> a;
    T.push_back(make_pair(a,1));
  }
  for(ll i=0;i<M;i++){
    ll b,c;
    cin >> b >> c;
    T.push_back(make_pair(c,b));
  }
  sort(T.begin(),T.end());
  reverse(T.begin(),T.end());
  ll ans=0;
  ll count=0;
  for(ll i=0;i<N;i++){
    if(count+T[i].second>N){
      ans+=T[i].first*(N-count);
      break;
    }
    else{
      ans+=T[i].first*T[i].second;
      count+=T[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}