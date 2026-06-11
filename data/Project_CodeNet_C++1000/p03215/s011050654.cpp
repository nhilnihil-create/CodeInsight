#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N, K; cin >> N >> K;

  int a[N];
  rep(i, N) {
    cin >> a[i];
  }
  vector<ll> sum;
  rep(l, N) {
    rep(r, l, N) {
      ll s = 0;
      rep(i, l, r+1) {
        s += a[i];
      }
      sum.push_back(s);
    }
  }
  ll x = 0;
  ll t = 1LL;
  rep(i, 39) t *= 2;
  rep(k, 40) {
    int count = 0;
    rep(i, sum.size()) {
      if (((x + t) & sum[i]) == x + t)
        ++count;
    }
    if (count >= K)
      x += t;
    t /= 2;
  }
  out(x);

  return 0;
}
