#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  ll N,M;
  cin>>N>>M;
  vector<ll> A(N);
  for(ll i(0);i<N;i++) cin>>A[i];
  vector<ll> r(N+1,0);
  
  for(ll i(0);i<N;i++){
    r[i+1] = r[i] + A[i];
  }

  map<ll,ll> cnt;
  for(ll i(0);i<N+1;i++){
    r[i] %= M;
    cnt[r[i]]++;
  }
  ll ans(0);
  for(auto mi:cnt) {
    ans += mi.second*(mi.second-1)/2;
  }
  cout << ans << endl;
  return 0;
}

