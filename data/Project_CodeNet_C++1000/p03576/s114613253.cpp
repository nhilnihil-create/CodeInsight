#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
int main() {
  int N, K; cin >> N >> K;

  int x[N], y[N];
  vector<pii> v;
  rep(i, N) {
    cin >> x[i];
    cin >> y[i];
    v.emplace_back(x[i], y[i]);
  }
  sort(x, x+N); sort(y, y+N);
  ll ans = 1LL * (x[N-1] - x[0]) * (y[N-1] - y[0]);
  rep(l, N) {
    rep(r, l, N) {
      rep(b, N) {
        rep(t, b, N) {
          int count = 0;
          rep(i, N) {
            int X = v[i].first, Y = v[i].second;
            if (x[l] <= X && X <= x[r] && y[b] <= Y && Y <= y[t]) {
              ++count;
            }
          }
          if (count >= K)
            chmin(ans, 1LL * (x[r]-x[l]) * (y[t]-y[b]));
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
