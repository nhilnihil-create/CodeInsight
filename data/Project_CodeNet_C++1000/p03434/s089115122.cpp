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
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a), greater<int>());
  int alice = 0, bob = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) alice += a[i];
    else bob += a[i];
  }
  cout << abs(alice - bob) << '\n';
}
