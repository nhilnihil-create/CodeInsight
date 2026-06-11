#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
typedef long double ld;
int main() {
  ld n, m, d;
  cin >> n >> m >> d;
  if (d == 0) {
    cout << fixed << setprecision(10) << (m - 1) / n << endl;
    return 0;
  }
  cout << fixed << setprecision(10) << (m - 1) * (n - d) * 2 / (n * n) << endl;
}