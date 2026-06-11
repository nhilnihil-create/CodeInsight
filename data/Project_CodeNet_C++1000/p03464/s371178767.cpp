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
  int k;
  cin >> k;
  vl a(k);
  vl ma(k + 1), mi(k + 1);
  REP(i, k) { cin >> a[i]; }
  if (a[k - 1] != 2) {
    cout << -1 << endl;
    return 0;
  }

  ma[k] = 2;
  mi[k] = 2;
  for (int i = k - 1; i >= 0; i--) {
    ma[i] = (ma[i + 1] / a[i]) * a[i];
    mi[i] = ((mi[i + 1] + a[i] - 1) / a[i]) * a[i];
    if (ma[i] < mi[i + 1] || mi[i] > ma[i + 1]) {
      cout << -1 << endl;
      return 0;
    }
    ma[i] += a[i] - 1LL;
  }

  cout << mi[0] << " " << ma[0] << endl;
}
