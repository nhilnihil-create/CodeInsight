#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

int main() {
  int N,K;
  cin >> N >> K;
  ll x0,x1,y0,y1;
  vector<ll> X(N),Y(N);
  rep(i,N){
    cin >> X[i] >> Y[i];
  }
  ll ans=8*1e18;
  rep(i,N)rep(j,N)rep(k,N)rep(l,N) {
    x0 = min({X[i],X[j],X[k],X[l]});
    x1 = max({X[i],X[j],X[k],X[l]});
    y0 = min({Y[i],Y[j],Y[k],Y[l]});
    y1 = max({Y[i],Y[j],Y[k],Y[l]});
    int cnt=0;
    rep(m,N) {
      if (x0<=X[m]&&X[m]<=x1&&y0<=Y[m]&&Y[m]<=y1) cnt++;
    }
    // cout << cnt << endl;
    if (cnt>=K) chmin(ans,(x1-x0)*(y1-y0));
  }
  cout << ans << endl;
} 