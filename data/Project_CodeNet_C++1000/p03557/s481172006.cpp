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
  int A[N], B[N], C[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  sort(A, A + N);
  sort(B, B + N);
  sort(C, C + N);
  long long tmp[N + 1];
  tmp[0] = 0;
  for (int i = 0; i < N; i++) tmp[i + 1] = lower_bound(A, A + N, B[i]) - A;
  for (int i = 1; i <= N; i++) tmp[i] += tmp[i - 1];
  long long ans = 0;
  for (int i = 0; i < N; i++) ans += tmp[lower_bound(B, B + N, C[i]) - B];
  cout << ans << '\n';
  return 0;
}
