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
int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  else gcd(b, a % b);
}
int main() {
  int N;
  ll X;
  cin >> N >> X;
  vector<ll> x(N);
  REP(i, N) cin >> x[i];
  vector<ll> dis(N);
  REP(i, N) dis[i] = abs(x[i] - X);
  sort(dis.begin(), dis.end());
  int ans = dis[0];
  for (int i = 1; i < N; i++) {
    ans = gcd(ans, dis[i]);
  }
  cout << ans << endl;
}