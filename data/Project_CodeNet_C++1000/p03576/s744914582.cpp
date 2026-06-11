#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int n, need;
  cin >> n >> need;
  vector<ll> x(n), y(n);
  rep(i, n) {
    cin >> x[i] >> y[i];
  }
  ll ans = LLONG_MAX;
  rep(i, n) {
    rep(j, n) {
      rep(k, n) {
        rep(s, n) {
          ll l = x[i];
          ll r = x[j];
          ll u = y[k];
          ll d = y[s];
          int cnt = 0;
          rep(kk, n) {
            if(l <= x[kk] && x[kk] <= r && d <= y[kk] && y[kk] <= u) cnt++;
          }
          if(cnt >= need) ans = min(ans, abs(r - l) * abs(u - d));
        }
      }
    }
  }
  cout << ans << endl;

}