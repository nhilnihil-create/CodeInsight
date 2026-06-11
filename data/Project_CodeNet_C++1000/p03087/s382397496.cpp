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
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<ll> ruiseki(N);
  ruiseki[0] = 0;
  for (int i = 1; i < N; i++) {
    ruiseki[i] = ruiseki[i - 1];
    if (S[i - 1] == 'A' && S[i] == 'C') ruiseki[i]++;
  }
  REP(i, Q) {
    int l, r;
    cin >> l >> r,l--,r--;
    ll ans = ruiseki[r] - ruiseki[l];
    cout << ans << endl;
  }
}