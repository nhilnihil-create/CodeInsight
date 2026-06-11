#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  ll ans = 0LL;
  for(ll i = 1; i<=K; i++){
    ll t = 0LL;
    for(ll j = (i+1)/2; j <=min(i,N); j++){
      ll s = 0LL;
      for(ll k = 0; k <= j;k++){
        ll u = 0LL;
        priority_queue<ll,vector<ll>,greater<ll>> q;
        for(ll l = 0; l<k;l++) q.push(v[l]);
        for(ll l = 0; l<j-k;l++) q.push(v[N-1-l]);
        for(ll l = 0; l<i-j;l++) q.pop();
        ll x = q.size();
        for(ll l = 0; l<x;l++) {
          u+=q.top();
          q.pop();
        }
        //cout<<i<<" "<<j<<" "<<k<<" "<<u<<" "<<endl;
        chmax(s,u);
      }
      chmax(t,s);
    }
    chmax(ans,t);
  }
  cout<<ans<<endl;
}