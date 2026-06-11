#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int cal(int x) {
  return (x + 9) / 10 * 10;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> a(5);
  for (auto &i : a) cin >> i;
  sort(all(a), [](int &a, int &b) -> bool {
    return (a - 1) % 10 > (b - 1) % 10;
  });
  int x = 0;
  for (int i = 0; i < 4; i++) {
    x = cal(x + a[i]);
  }
  cout << x + a[4] << '\n';
}
