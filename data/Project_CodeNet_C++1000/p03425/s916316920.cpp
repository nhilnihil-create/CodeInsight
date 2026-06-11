#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<int> cnt(5, 0);
  rep(i, n) {
    switch (s[i][0]) {
      case 'M': ++cnt[0]; break;
      case 'A': ++cnt[1]; break;
      case 'R': ++cnt[2]; break;
      case 'C': ++cnt[3]; break;
      case 'H': ++cnt[4]; break;
      default: break;
    }
  }

  ll ans = 0;
  rep(i, 5) rep(j, 5) rep(k, 5) {
    if (i >= j || j >= k) continue;
    ans += (ll) cnt[i] * cnt[j] * cnt[k];
  }
  cout << ans << endl;
  return 0;
}