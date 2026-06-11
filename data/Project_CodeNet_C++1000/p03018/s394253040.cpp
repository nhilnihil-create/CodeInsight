#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string s; cin >> s;
  int n = s.size();
  int fa = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      fa++;
      continue;
    }
    if (i + 1 == n) break;
    if (s[i] == 'B' && s[i + 1] == 'C') {
      ans += fa;
      i++;
    } else {
      fa = 0;
    }
  }
  cout << ans << endl;

  return 0;
}
