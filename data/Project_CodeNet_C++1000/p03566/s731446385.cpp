#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
using V = vector<ll>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll hcnt[300005],wcnt[300005];

int main() {
  ll N;
  cin>>N;
  vector<lb> t(N),v(N);
  rep(i,N) cin>>t[i];
  rep(i,N) cin>>v[i];
  vector<lb> V(40005,INF);
  ll T = 0;
  ll cnt = 0;
  rep(i,N) cnt += t[i]*2;
  rep(i,cnt+1){
    chmin(V[i],(lb)i/2);
    chmin(V[cnt-i],(lb)i/2);
  }
  rep(i,N){
    for(int j = T; j < T+t[i]*2;j++){
      chmin(V[j],v[i]);
    }
    rep(j,T){
      chmin(V[T-j-1],v[i]+(lb)(j+1)/2);
    }
    for(int j = T+t[i]*2;j<cnt+1;j++){
      chmin(V[j],v[i]+(lb)(j-T-t[i]*2)/2);
    }
    T += 2*t[i];
  }
  lb ans = 0;
  for(int i = 1; i <= cnt; i++){
    ans += (lb)(V[i]+V[i-1])/4;
  }
  cout<<fixed<<setprecision(5);
  cout<<ans<<endl;
}