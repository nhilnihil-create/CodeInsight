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
  int n;
  cin >> n;
  vector<double> a(n);
  REP(i, n) { cin >> a[i]; }
  double mid = 0;
  REP(i, n) { mid += a[i]; }
  mid /= n;

  int ans = 0;
  double m = 10000;
  REP(i, n) {
    if (m > abs(a[i] - mid)) {
      ans = i;
      m = abs(a[i] - mid);
    }
  }
  cout << ans << endl;
}
