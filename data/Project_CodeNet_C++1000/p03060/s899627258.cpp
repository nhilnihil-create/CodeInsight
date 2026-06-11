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
  int V[N];
  for (int i = 0; i < N; i++) cin >> V[i];
  for (int i = 0; i < N; i++) {
    int C;
    cin >> C;
    V[i] -= C;
  }
  sort(V, V + N);
  int ans = 0;
  for (int i = N - 1; i >= 0 && V[i] > 0; i--) ans += V[i];
  cout << ans << '\n';
  return 0;
}
