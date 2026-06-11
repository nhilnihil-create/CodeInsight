#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  ll n;
  cin >> n;

  FOR(i, 1, 3501) {
    FOR(j, 1, 3501) {
      ll frac = i * j * n;
      ll denomi = 4 * i * j - n * i - n * j;
      if (denomi <= 0) continue;
      if (frac % denomi == 0) {
        cout << i << " " << j << " " << frac / denomi << endl;
        return 0;
      }
    }
  }
}