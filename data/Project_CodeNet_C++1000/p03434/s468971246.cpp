#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;
vi a;

void input() {
  cin >> n;

  a.resize(n);
  for (auto&& i : a)
    cin >> i;
}

void solve() {
  sort(a.rbegin(), a.rend());

  int x = 0;
  int y = 0;

  for (int i = 0; i < n; i += 2)
    x += a[i];

  for (int i = 1; i < n; i += 2)
    y += a[i];

  cout << x - y << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  _times = 3;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
