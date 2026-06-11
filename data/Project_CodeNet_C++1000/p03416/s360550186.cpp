#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

bool palin(string s) {
  int n = s.size();
  for (int j = 0; j < n; j++) {
    if (s[j] != s[n - j - 1]) return 0;
  }
  return 1;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    if (palin(to_string(i))) ans++;
  }
  cout << ans << '\n';
}
