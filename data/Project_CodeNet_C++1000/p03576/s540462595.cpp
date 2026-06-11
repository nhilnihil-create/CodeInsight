#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<62;
const ll mod = 1000000007LL;

ll next_combination(ll sub) {//組み合わせ全列挙に使うやつ
    ll x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main() {
  ll N,K;
  cin>>N>>K;
  vector<vector<ll>> v(N,vector<ll>(2));
  vector<ll> X(N),Y(N);
  for(ll i = 0LL; i < N; i++) {
    ll x,y;
    cin>>x>>y;
    X[i]=x;
    Y[i]=y;
    v[i][0]=x;
    v[i][1]=y;
  }
  sort(X.begin(),X.end());
  sort(Y.begin(),Y.end());
  ll bit = (1LL<<2)-1LL;
  vector<vector<ll>> xp,yp;
  vector<vector<ll>> num(N+1,vector<ll>(N+1));
  for(ll i = 0LL; i < N; i++) {
    for(ll j = 0LL; j < N; j++){
      ll cnt = 0LL;
      for(ll k = 0LL; k < N; k++){
        if(X[i]>=v[k][0]&&Y[j]>=v[k][1]) cnt++;
      }
      num[i+1][j+1]=cnt;
    }
  }
  for(ll i = 0; i < N+1; i++) {
    num[i][0]=0LL;
    num[0][i]=0LL;
  }
  for(;bit<(1LL<<N);bit = next_combination(bit)){
    vector<ll> xx;
    for(ll i = 0LL; i < N; i++){
      if(bit&(1LL<<i)) xx.push_back(i);
    }
    sort(xx.begin(),xx.end());
    xp.push_back(xx);
  }
  bit = (1LL<<2)-1;
  for(;bit<(1LL<<N);bit = next_combination(bit)){
    vector<ll> yy;
    for(ll i = 0LL; i < N; i++){
      if(bit&(1LL<<i)) yy.push_back(i);
    }
    sort(yy.begin(),yy.end());
    yp.push_back(yy);
  }
  ll ans = INF;
  for(auto x:xp){
    for(auto y:yp){
      ll l = x[0],r=x[1],d=y[0],u=y[1];
      ll t = num[r+1][u+1]-num[r+1][d]-num[l][u+1]+num[l][d];
      if(t>=K) chmin(ans,(X[r]-X[l])*(Y[u]-Y[d]));
    }
  }
  cout<<ans<<endl;
}