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
  vector<int> l(n + 1);
  l[0] = 2;
  l[1] = 1;
  for (int i = 2; i <= n; i++) {
    l[i] = l[i - 1] + l[i - 2];
  }
  cout << l[n] << '\n';
}
