#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod));
  ll t = longpow(n, a / 2, mod);
  return (t * t);
}
int main() {
  int N, M;
  cin >> N >> M;
  cout << (1900 * M + 100 * (N - M)) * longpow(2, M, MOD) << endl;
}