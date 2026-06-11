#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int a[5][105];

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= 2; i++)
  for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
    a[i][j] += max(a[i - 1][j], a[i][j - 1]);
  }
  cout << a[2][n] << '\n';
}
