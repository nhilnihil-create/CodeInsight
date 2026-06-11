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
  ll N, M;
  cin >> N >> M;
  vector<pair<int, ll>> A(0);
  REP(i, N) {
    ll a;
    cin >> a;
    A.push_back(pair<int, ll>(a, 1));
  }
  REP(i, M) {
    ll b, c;
    cin >> b >> c;
    A.push_back(pair<int, ll>(c, b));
  }
  sort(A.begin(), A.end(), greater<pair<int, ll>>());
  ll ans = 0;
  ll i = 0;
  while (N > 0) {
    if (N >= A[i].second) {
      ans += (ll)A[i].first * A[i].second;
      N -= A[i].second;
    } else {
      ans += (ll)A[i].first * N;
      N = 0;
    }
    i++;
  }
  cout << ans << endl;
}