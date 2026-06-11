#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  char s[n][n];
  REP(i, n) REP(j, n) cin >> s[i][j];
  int ans = 0;
  REP(k, n) {
    char t[n][n];
    REP(i, n) REP(j, n) t[i][j] = s[i][(j + k) % n];
    bool ok = true;
    REP(i, n) REP(j, n) {
      if (t[i][j] != t[j][i]) ok = false;
    }
    if (ok) ans++;
  }
  cout << ans * n << endl;
  return 0;
}