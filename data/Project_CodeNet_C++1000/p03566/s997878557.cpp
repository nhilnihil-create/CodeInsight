#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n-1; i >= 0; --i)
#define FOR(i, n, m) for (int i = n; i < m; ++i)
#define FORR(i, n, m) for (int i = m-1; i >= n; --i)

const int INF = 1e9+9;
const int NN = 210;
const int MAX = 2e4+10;

int T[NN], Vt[MAX], Vi[NN];
int N;

int main() {

  memset(Vt, INF, sizeof(Vt));

  cin >> N;

  REP (i, N) cin >> T[i+1];
  REP (i, N) cin >> Vi[i];

  T[0] = 0;
  Vt[0] = 0;
  int sum = 0;

  REP (i, N) {
    sum += T[i+1];
    T[i+1] = sum;
    FOR (t, T[i], T[i+1])
      Vt[t+1] = min(Vt[t]+1, Vi[i]);
  }

  Vt[sum] = 0;
  REPR (i, N) FORR (t, T[i], T[i+1])
    Vt[t] = min(Vt[t], min(Vi[i], Vt[t+1]+1));

  REP (i, N) FOR (t, T[i], T[i+1])
    Vt[t+1] = min(Vt[t+1], Vt[t]+1);

  double ans = 0;
  REP (i, N) FOR (t, T[i], T[i+1]) {
    if (Vt[t] != Vt[t+1]) ans += 1.0*(Vt[t]+Vt[t+1])/2.0;
    else {
      ans += Vt[t];
      if (Vt[t] < Vi[i]) ans += 0.25;
    }
  }

  cout << fixed << setprecision(10) << ans << endl;

}