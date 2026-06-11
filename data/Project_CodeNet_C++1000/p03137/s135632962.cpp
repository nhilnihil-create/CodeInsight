#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i= (a); i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() { int N, M;
  cin >> N >> M;
  vector<int> X(M);

  REP(i, M) cin >> X[i];
  vector<int> koma(N);
  sort(X.begin(), X.end());
  ll ans = X[M-1]-X[0];
  vector<int> aida(M - 1);
  REP(i, M - 1) { aida[i] = X[i + 1] - X[i]; }
  sort(aida.begin(), aida.end());
  REP(i, N-1) {
    if (M - 2 - i < 0) break;
    ans -= aida[M - 2 - i];
  }
  ans = max(ans, (ll)0);
  cout << ans << endl;
}