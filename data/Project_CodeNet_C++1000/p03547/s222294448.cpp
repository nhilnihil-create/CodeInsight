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

  char a, b;
  cin >> a >> b;

  if (a < b) {
    cout << "<"
         << "\n";
  } else if (a > b) {
    cout << ">"
         << "\n";
  } else {
    cout << "="
         << "\n";
  }
}