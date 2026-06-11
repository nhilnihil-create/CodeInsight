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
  ll N, A, B, C, D, E;
  cin >> N >> A >> B >> C >> D >> E;
  ll ans = 0;
  ans += (N + A - 1) / A;
  ll tmp = max((ll)0, N - (ans - 1) * B);  //今A-B間にいる人
  ans += max((tmp + B - 1) / B, (ll)1);
  tmp = max((ll)0, N - (ans - 2) * C);
  ans += max((tmp + C - 1) / C, (ll)1);
  tmp = max((ll)0, N - (ans - 3) * D);
  ans += max((tmp + D - 1) / D, (ll)1);
  tmp = max((ll)0, N - (ans - 4) * E);
  ans += max((tmp + E - 1) / E, (ll)1);
  cout << ans << endl;
}