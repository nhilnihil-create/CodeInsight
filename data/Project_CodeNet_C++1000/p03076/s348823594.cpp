#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> v(5);
  for (int i = 0; i < 5; i++) cin >> v[i];
  int ans = INT_MAX;
  sort(v.begin(), v.end());
  for (int cnt = 5 * 4 * 3 * 2 * 1; cnt--;) {
    int tmp = 0;
    for (int i = 0; i < 5; i++) {
      tmp = (tmp + 9) / 10 * 10;
      tmp += v[i];
    }
    ans = min(ans, tmp);
    next_permutation(v.begin(), v.end());
  }
  cout << ans << '\n';
  return 0;
}
