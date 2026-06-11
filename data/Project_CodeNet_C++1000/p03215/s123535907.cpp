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
  for(ll i = 0LL; i < N; i++) cin>>v[i];
  vector<ll> S(N);
  for(ll i = 0LL; i < N; i++){
    if(i==0LL) S[i]=v[i];
    else S[i]=S[i-1]+v[i];
  }
  unordered_map<ll,ll> m;
  for(ll i = 0LL; i < N-1; i++){
    for(ll j = i+1; j < N; j++){
      m[S[j]-S[i]]++;
    }
  }
  for(ll i = 0LL; i < N ;i++) m[S[i]]++;
  ll cnt = 0LL;
  ll M = S[N-1];
  while(M>0LL) {
    M=(M>>1);
    cnt++;
  }
  ll ans = 0LL;
  for(ll i = cnt; i >=0LL; i--){
    ll x = ans + (1LL<<i);
    ll num = 0;
    for(auto y:m){
      if((y.first&x)==x) num+= y.second;
    }
    if(num>=K) ans=x;
  }
  cout<<ans<<endl;
}