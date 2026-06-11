#include <iostream>
#include <limits>

using namespace std;
using ll = long long;

#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"
const ll INF = numeric_limits<ll>::max();
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N;
  ll C;
  in(N); in(C);

  ll x[N], v[N];
  rep(i, N) {
    in(x[i]);
    in(v[i]);
  }
  ll sum_l[N+1], sum_r[N+1];
  sum_l[0] = sum_r[N] = 0;
  rep(i, N) sum_l[i+1] = sum_l[i] + v[i];
  rrep(i, N-1) sum_r[i] = sum_r[i+1] + v[i];
  rep(i, N) {
    sum_l[i+1] -= x[i];
    sum_r[i] -= C - x[i];
  }

  ll max_l[N+1], max_l2[N+1];
  max_l[0] = max_l2[0] = 0;
  rep(i, N) {
    max_l[i+1] = max(max_l[i], sum_l[i+1]);
    max_l2[i+1] = max(max_l2[i], sum_l[i+1] - x[i]);
  }

  ll ans = 0;
  chmax(ans, max_l[N]);
  rrep(r, N-1) {
    if (r == 0)
      chmax(ans, sum_r[r]);
    else {
      chmax(ans, sum_r[r] + max_l[r] - (C - x[r]));
      chmax(ans, sum_r[r] + max_l2[r]);
    }
  }
  out(ans);

  return 0;
}
