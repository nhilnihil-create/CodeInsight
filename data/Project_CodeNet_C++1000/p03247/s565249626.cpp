#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, n, m) for (ll i = n; i < m; ++i)

const int MAX = 1010;
const int M = 39;
const ll SUM_D = (1l << M)-1;
int N;
ll U[MAX], V[MAX];
string MODE[4];

int main() {

  cin >> N;

  int even = 0;
  REP (i, N) {
    ll x, y;
    cin >> x >> y;
    U[i] = x+y;
    V[i] = x-y;
    even |= 1<<(abs(U[i])%2);
  }

  MODE[3] = "R";
  MODE[2] = "U";
  MODE[1] = "D";
  MODE[0] = "L";

  if (even == 3) {
    cout << -1 << endl;
    return 0;
  }

  even %= 2;
  if (even) {
    cout << M+1 << endl;
    cout << "1 1";
  } else {
    cout << M << endl;
    cout << 1;
  }
  REP (i, M-1) cout << " " << (1l<<(i+1));
  cout << endl;

  REP (n, N) {
    ll u = U[n], v = V[n];
    if (even) {
      u++; v++;
      cout << "L";
    }

    bool pU = (u >= 0), pV = (v >= 0);
    ll dU = SUM_D - abs(u);
    ll dV = SUM_D - abs(v);
    FOR (m, 1, M+1) {
      int c = ((((dU>>m)&1)^pU)<<1) + ((dV>>m)&1)^pV;
      cout << MODE[c];
    }
    cout << endl;
  }

  return 0;

}