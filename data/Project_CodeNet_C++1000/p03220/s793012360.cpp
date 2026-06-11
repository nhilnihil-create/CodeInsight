#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  double t, a;
  cin >> t >> a;
  double mi = 2e9;
  int sv = 0;
  for (int i = 1; i <= n; i++) {
    double d;
    cin >> d;
    d = t - d * 0.006;
    if (abs(a - d) < mi) {
      mi = abs(a - d);
      sv = i;
    }
  }
  cout << sv << '\n';
}
