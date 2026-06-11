#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll N,M;
  cin>>N>>M;
  vector<vector<ll>> v(8,vector<ll>(N));
  for(ll i = 0LL; i < N; i++) {
    vector<ll> x(3);
    cin>>x[0]>>x[1]>>x[2];
    rep(j,8){
      ll t = 0LL;
      rep(k,3){
        if(j&(1<<k))t-=x[k];
        else t+=x[k];
      }
      v[j][i]=t;
    }
  }
  ll ans = 0LL;
  rep(i,8){
    sort(v[i].begin(),v[i].end());
    reverse(v[i].begin(),v[i].end());
  }
  rep(i,8){
    ll t = 0LL;
    for(ll j = 0LL; j < M; j++){
      t+=v[i][j];
    }
    chmax(ans,t);
  }
  cout<<ans<<endl;
}