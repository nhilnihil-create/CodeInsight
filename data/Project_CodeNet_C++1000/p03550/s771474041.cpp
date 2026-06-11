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
  int n, w, z;
  cin >> n >> z >> w;
  vi a(n);
  REP(i, n) { cin >> a[i]; }

  if (n == 1) {
    cout << abs(a[0] - w) << endl;
  } else {
    cout << max(abs(a[n - 2] - a[n - 1]), abs(w - a[n - 1])) << endl;
  }
}
