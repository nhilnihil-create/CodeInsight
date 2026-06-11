#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  ll ans = 0;
  sort(A.begin(), A.end());
  REP(i, N - K+1) {
    ll num = abs(A[i] - A[i + K-1]);
    ans = ans!=0?min(ans, num):num;
  }
  cout << ans << endl;
}