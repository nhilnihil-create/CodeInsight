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
int main() {
  int N, K;
  long double ans = 0;
  cin >> N >> K;
  REP(i, N) {
    long double kakuritu = 1;
    ll now = i + 1;
    while (now < K) {
      now *= 2;
      kakuritu *= 0.5;
    }
    ans += kakuritu;
  }
  cout << setprecision(100) << fixed << ans / N << endl;
}