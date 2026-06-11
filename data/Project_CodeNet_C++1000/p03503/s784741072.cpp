#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

int main() {
  ll N;
  cin>>N;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++){
    ll t = 0;
    for(ll j = 0; j < 10; j++){
      ll s;
      cin>>s;
      t+=(s<<j);
    }
    v[i]=t;
  }
  vector<vector<ll>> w(N,vector<ll>(11));
  for(ll i = 0; i < N; i++){
    for(ll j = 0; j < 11; j++){
      cin>>w[i][j];
    }
  }
  ll ans = -INF;
  for(ll i = 1; i < (1LL<<10);i++){
    ll p = 0;
    for(ll j = 0; j < N; j++){
      p+=w[j][__builtin_popcount(i&v[j])];
    }
    chmax(ans,p);
  }
  cout<<ans<<endl;
}