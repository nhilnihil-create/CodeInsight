#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool ans[85][85][13000];

int main() {
  ll N,K;
  cin>>N>>K;
  vector<P> v(N);
  rep(i,N) cin>>v[i].second>>v[i].first;
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  ll p = K-1;
  ll total = 0;
  ll ans = 0;
  map<ll,ll> m;
  ll cnt = 0;
  rep(i,K){
    total += v[i].first;
    if(m[v[i].second]==0) cnt++;
    m[v[i].second]++;
  }
  ans = total + cnt*cnt;
  priority_queue<ll,vector<ll>,greater<ll>> q;
  rep(i,K){
    if(m[v[K-i-1].second]!=1) {
      q.push(v[K-i-1].first);
      m[v[K-i-1].second]--;
    }
  }
  priority_queue<ll> pl;
  for(int i = K; i < N; i++){
    if(m[v[i].second]==0) pl.push(v[i].first);
    m[v[i].second]++;
  }
  while(!q.empty()&&!pl.empty()){
    ll t = q.top();
    ll s = pl.top();
    q.pop();
    pl.pop();
    total -= t;
    total += s;
    cnt++;
    chmax(ans,total+cnt*cnt);
  }
  cout<<ans<<endl;
}