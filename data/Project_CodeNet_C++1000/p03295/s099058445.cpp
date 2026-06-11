#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

#define INF (i64)(1e18)
#define MOD (i64)(1e9+7)
#define REP(i, n) for(i64 i = 0; i < (n); i++)
#define RANGE(i, a, b) for(i64 i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((i64)(v).size())
template<class T> inline void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if (a > b) a = b; }

int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int>> v(m);
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    v[i] = {a, b};
  }
  sort(ALL(v), [](tuple<int, int> p1, tuple<int, int> p2) { return get<1>(p1) < get<1>(p2); });
  int prev = get<1>(v[0])-1;
  int ans = 1;
  RANGE(i, 1, m) {
    if (get<0>(v[i]) > prev) {
      ans++;
      prev = get<1>(v[i])-1;
    }
  }
  cout << ans << endl;
  return 0;
}
