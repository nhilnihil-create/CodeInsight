#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll ts = 1000000007;

int main() {
  string s;
  cin >> s;

  ll ans = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '+') {
      ans++;
    } else {
      ans--;
    }
  }

  cout << ans << endl;
}