#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  string s;
  vector<ll> cnt(5);
  rep(i, n) {
    cin >> s;
    switch (s[0]) {
      case 'M':
        cnt[0]++;
        break;

      case 'A':
        cnt[1]++;
        break;

      case 'R':
        cnt[2]++;
        break;

      case 'C':
        cnt[3]++;
        break;

      case 'H':
        cnt[4]++;
        break;

      default:
        break;
    }
  }

  // rep(i, n) cerr << cnt[i] << endl;

  ll ans = 0;
  for (int i = 0; i <= 2; i++) {
    for (int j = i + 1; j <= 3; j++) {
      for (int k = j + 1; k <= 4; k++) {
        ans += cnt[i] * cnt[j] * cnt[k];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
