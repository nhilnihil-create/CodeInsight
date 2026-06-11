#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> vb(60,0LL);
  for(ll i = 0LL; i < N; i++) {
    ll x;
    cin>>x;
    bitset<60> y(x);
    for(ll j = 0LL; j < 60; j++) {
      if(y.test(j)) vb[j]++;
    }
  }
  ll k = 0LL;
  ll ans=0LL;
  for(ll i = 59;i >=0; i--){
    if((1LL<<i)+k<=K&&N-vb[i]>=N/2LL+1LL){
      k+=(1LL<<i);
      ans+=(1LL<<i)*(N-vb[i]);
    }
    else ans+=(1LL<<i)*vb[i];
  }
  cout<<ans <<endl;
}
