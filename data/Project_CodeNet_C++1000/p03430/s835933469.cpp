#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define debugArray(x, n)                                      \
  cerr << __LINE__ << ": " << #x << " = {";                   \
  for (long long hoge = 0; (hoge) < (long long)(n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];                   \
  cerr << "}" << '\n'
#define debugMatrix(x, h, w)                                         \
  cerr << __LINE__ << ": " << #x << " =\n";                          \
  for (long long hoge = 0; (hoge) < (long long)(h); ++(hoge)) {      \
    cerr << ((hoge ? " {" : "{{"));                                  \
    for (long long fuga = 0; (fuga) < (long long)(w); ++(fuga))      \
      cerr << ((fuga ? ", " : "")) << x[hoge][fuga];                 \
    cerr << "}" << (hoge + 1 == (long long)(h) ? "}" : ",") << '\n'; \
  }
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#define debugMatrix(x, h, w) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string S;
  cin >> S;
  int K;
  cin >> K;
  int N = S.length();
  long long dp[N][N][K + 1];
  for (int i = 0; i < N; i++)
    for (int k = 0; k <= K; k++) dp[i][i][k] = 1;
  for (int i = 0; i + 1 < N; i++)
    for (int k = 0; k <= K; k++)
      dp[i][i + 1][k] = S[i] == S[i + 1] || k > 0 ? 2 : 1;
  for (int d = 2; d < N; d++)
    for (int l = 0; l + d < N; l++) {
      int r = l + d;
      for (int k = 0; k <= K; k++) {
        dp[l][r][k] = max(dp[l + 1][r][k], dp[l][r - 1][k]);
        if (S[l] == S[r]) {
          dp[l][r][k] = max(dp[l][r][k], dp[l + 1][r - 1][k] + 2);
        } else if (k > 0) {
          dp[l][r][k] = max(dp[l][r][k], dp[l + 1][r - 1][k - 1] + 2);
        }
      }
    }
  cout << dp[0][N - 1][K] << '\n';
  return 0;
}
