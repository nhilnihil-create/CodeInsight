#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
template <typename T>
ll extGCD(T a, T b) {
  if (b == 0) {
    return a;
  }
  ll d = extGCD(b, a % b);
  return d;
}
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> L(N + 1), R(N + 1);
  REP(i, N) { cin >> A[i]; }
  L[0] = 0;
  REP(i, N) { L[i + 1] = extGCD(L[i], A[i]); }
  R[N] = 0;
  for (int i = N - 1; i >= 0; i--) {
    R[i] = extGCD(R[i + 1], A[i]);
  }
  int ans = 0;
  REP(i, N) { ans = max<ll>(ans, extGCD(L[i], R[i + 1])); }
  cout << ans << endl;
}