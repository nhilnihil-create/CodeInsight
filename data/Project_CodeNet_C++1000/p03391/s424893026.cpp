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

int main() {
  ll N;
  cin>>N;
  vector<ll> A(N),B(N);
  rep(i,N) cin>>A[i]>>B[i];
  ll cnt = 0;
  rep(i,N){
    if(A[i]>B[i]) cnt++;
  }
  ll ans = 0;
  if(cnt == 0) ans = 0;
  else {
    ll b = INF;
    rep(i,N) {
      ans += A[i];
      if(A[i]>B[i]) chmin(b,B[i]);
    }
    ans -= b;
  }
  cout<<ans<<endl;
}