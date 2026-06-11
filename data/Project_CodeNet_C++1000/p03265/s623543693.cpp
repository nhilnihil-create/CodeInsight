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
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int tx = x2 - x1;
  int ty = y2 - y1;
  cout << x2 - ty << ' ' << y2 + tx << ' ';
  cout << x1 - ty << ' ' << y1 + tx << '\n';
}
