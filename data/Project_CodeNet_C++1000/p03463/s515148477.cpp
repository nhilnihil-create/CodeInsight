#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = 100100100;
const double PI = 3.14159265358979323846;
typedef long long ll;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n, a, b;
  string winner;
  cin >> n >> a >> b;
  if ((b - a) % 2 == 0) {
    winner = "Alice";
  } else if ((b - a) % 2 == 1) {
    winner = "Borys";
  }

  cout << winner << endl;
  return 0;
}