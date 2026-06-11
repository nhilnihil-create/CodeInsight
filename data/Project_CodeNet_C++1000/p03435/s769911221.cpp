#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int a[5][5];

void solve() {
  for (int i = 1; i <= 3; i++)
  for (int j = 1; j <= 3; j++) {
    cin >> a[i][j];
  }
  for (int i = 2; i <= 3; i++)
  for (int j = 2; j <= 3; j++) {
    if (a[i][j] != a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]) {
      cout << "No" << '\n';
      return;
    }
  }
  cout << "Yes" << '\n';
}


signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
