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
  int N;
  cin >> N;
  int ct = 0, cx = 0, cy = 0;
  bool isok = true;
  for (int i = 0; i < N; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    int dist = abs(x - cx) + abs(y - cy), dt = t - ct;
    isok &= dist <= dt;
    isok &= !((dist ^ dt) & 1);
    ct = t, cx = x, cy = y;
  }
  cout << (isok ? "Yes" : "No") << '\n';
  return 0;
}
