#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<int, int> P;
int main() {
  ll N;
  cin >> N;
  REP(a, 3600) REP(b, 3600) {
    if (a == 0 || b == 0) continue;
    if (4 * a * b  - N * a - N * b <= 0) continue;
    //cout << a << " " << b << endl;
    if ((N * a * b) % (4 * a * b - N * a - N * b) == 0) {
      cout << a << " " << b << " ";
      cout << (N * a * b) / (4 * a * b - N * a - N * b) << endl;
      return 0;
    }
  }
}