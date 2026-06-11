#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
#define rep(i, n) for(int i=0;i<n;i++)
ll X, Y, Z, K;
vector<ll> a, b, c;
vector<ll> ans;
bool solve(ll T, bool sp) {
  int cnt = 0;
  rep(i, X) {
    rep(j, Y) {
      rep(k, Z) {
        if(a[i]+b[j]+c[k]<T) break;
        if(sp) ans.emplace_back(a[i]+b[j]+c[k]);
        cnt++;
        if(!sp && cnt >= K) return true;
      }
    }
  }
  return false;
}
int main() {
  cin >> X >> Y >> Z >> K;
  a.resize(X);b.resize(Y);c.resize(Z);
  rep(i, X) cin >> a[i];
  rep(i, Y) cin >> b[i];
  rep(i, Z) cin >> c[i];
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  ll front = 0;
  ll back = 30000000000;
  while(front != back) {
    ll half = (back + front) / 2;
    if(back == front+1) {
      back = front;
    }
    else if(solve(half, false)) front = half;
    else back = half - 1;
  }
  solve(front, true);
  sort(ans.rbegin(), ans.rend());
  rep(i, K) cout << ans[i] << endl;
  return 0;
}
