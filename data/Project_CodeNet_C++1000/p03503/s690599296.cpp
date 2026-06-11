#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int F[110][12];
int P[110][13];
int main() {
  ll N;
  cin >> N;
  REP(i, N) {
    REP(j, 10) { cin >> F[i][j]; }
  }
  REP(i, N) REP(j, 11) { cin >> P[i][j]; }
  ll ans = -1e15;
  for (int bit = 1; bit < (1 << 10); bit++) {
    ll tmp = 0;
    vector<ll> A(N, 0);
    REP(i, 10) {
      ll tk = (1 << i);
      tk &= bit;
      if (tk == 0) continue;
      REP(j, N) {
        if (F[j][i] == 1) A[j]++;
      }
    }
    REP(i, N) { tmp += P[i][A[i]]; }
    ans = max(tmp, ans);
  }
  cout << ans << endl;
}