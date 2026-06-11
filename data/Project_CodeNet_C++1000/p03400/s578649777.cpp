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

  ll n, d, x;
  cin >> n >> d >> x;

  REP(i, n) {
    ll a;
    cin >> a;

    for (int j = 0; j * a + 1 <= d; j++) {
      x++;
    }
  }

  cout << x << "\n";
}