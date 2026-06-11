#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll ts = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  bool can = true;

  ll a, b;
  string s;
  cin >> a >> b >> s;

  for (int i = 0; i < a; i++)
    if (!('0' <= s[i] && s[i] <= '9')) {
      puts(" No ");
      return 0;
    }
  if (s[a] != '-') {
    puts(" No ");
    return 0;
  }
  for (int i = a + 1; i <= a + b; i++)
    if (!('0' <= s[i] && s[i] <= '9')) {
      puts(" No ");
      return 0;
    }
  puts(" Yes ");
}