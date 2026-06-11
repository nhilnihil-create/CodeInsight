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

  ll d;
  cin >> d;

  if (d == 25) {
    cout << "Christmas"
         << "\n";
  } else if (d == 24) {
    cout << "Christmas Eve"
         << "\n";
  } else if (d == 23) {
    cout << "Christmas Eve Eve"
         << "\n";
  } else if (d == 22) {
    cout << "Christmas Eve Eve Eve"
         << "\n";
  }
}