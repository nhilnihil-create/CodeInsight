#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll ts = 1000000007;

int main() {
  string n;
  cin >> n;
  REP(i, 3) {
    if (n[i] == '1') {
      n[i] = '9';
    } else if (n[i] == '9') {
      n[i] = '1';
    }
  }
  cout << n << endl;
}