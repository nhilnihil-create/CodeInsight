#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int mypow(int a, int b) {
  if (b == 0) return 1;
  if (b % 2) return a * mypow(a, b / 2) * mypow(a, b / 2);
  return mypow(a, b / 2) * mypow(a, b / 2);
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  // ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ans = 1;
  for (int i = 2; i * i <= n; i++) {
    int t = i * i;
    while (t * i <= n) t *= i;
    ans = max(ans, t);
  }
  cout << ans << '\n';
}
