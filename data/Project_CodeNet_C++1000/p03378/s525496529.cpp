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

  ll n, m, x;
  cin >> n >> m >> x;

  ll a;
  ll l = 0, r = 0;
  REP(i, m) {
    cin >> a;
    if (a < x) {
      l++;
    } else {
      r++;
    }
  }
  cout << min(l, r) << "\n";
}