#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getbit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

map<int, map<int, double>> mem;

double cal(vector<double> &a, int k, int n) {
  if (k == 0) return 1.0;
  if (mem[n].count(k)) return mem[n][k];
  if (n == k) {
    double ret = 1.0;
    for (int i = 1; i <= n; i++) {
      ret *= a[i];
    }
    return mem[n][k] = ret;
  }
  double ret = 0.0;
  ret += cal(a, k - 1, n - 1) * a[n];
  ret += cal(a, k, n - 1) * (1 - a[n]);
  return mem[n][k] = ret;
}

void MAIN() {
  int n; cin >> n;
  vector<double> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << fixed << setprecision(10);
  cout << cal(a, (n + 1) / 2, n) << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
