#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; in(N);

  int l[N+2], r[N+2], v[N+2];
  l[0] = l[1] = 0;
  r[0] = 0;
  rep(i, N) {
    int t; in(t);
    l[i+2] = r[i+1] = t + l[i+1];
  }
  int T = r[N];
  l[N+1] = r[N+1] = T;

  v[0] = v[N+1] = 0;
  rep(i, N)
    in(v[i+1]);

  double ans = 0;
  rep(a, 2*T) {
    double v_x = numeric_limits<double>::max();
    rep(i, N+2) {
      auto v_a = [&](int a) {
        if (a <= 2 * l[i])
          return (double)v[i]+(l[i]-a/2.0);
        else if (2*l[i] <= a && a <= 2*r[i])
          return (double)v[i];
        else
          return (double)v[i]+(a/2.0-r[i]);
      };
      chmin(v_x, 0.25*(v_a(a) + v_a(a+1)));
    }
    ans += v_x;
  }
  out(fixed << setprecision(15) << ans);

  return 0;
}
