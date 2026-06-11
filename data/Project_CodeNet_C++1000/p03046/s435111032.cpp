#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int m, k;
  cin >> m >> k;
  int n = (1 << m);
  if (k == 0) {
    REP(i, n) { cout << i << " "; }
    for (int i = n - 1; i >= 0; i--) {
      cout << i;
      if (i != 0) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
    return 0;
  }

  if (m == 1 || n <= k) {
    cout << -1 << endl;
    return 0;
  }

  cout << k << endl;
  REP(i, n) {
    if (i == k)
      continue;
    cout << i << " ";
  }
  cout << k << " ";
  for (int i = n - 1; i >= 0; i--) {
    if (i == k)
      continue;
    cout << i;
    if (i != 0) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}
