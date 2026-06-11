#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 60;
const int M = 3;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  ll k;
  cin >> k;
  if (abs(a - b) > 1e18) {
    cout << "Unfair" << endl;
    return 0;
  }
  if (k % 2 == 0)
    cout << a - b << endl;
  else
    cout << b - a << endl;

  return 0;
}
