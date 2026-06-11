#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll ts = 1000000007;

int main() {
  ll k;
  cin >> k;

  if (k % 2 == 0) {
    cout << (k / 2) * (k / 2) << endl;
  } else {
    cout << (k / 2) * (k / 2 + 1) << endl;
  }
}