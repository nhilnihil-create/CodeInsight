#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  string s; cin >> s;
  int n = s.size();
  int ans = n;
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] != s[i + 1]) {
      ans = min(ans, max(i + 1, n - (i + 1)));
    }
  }
  printf("%d\n", ans);
  return 0;
}
