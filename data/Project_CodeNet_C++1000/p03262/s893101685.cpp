#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <numeric>
#include <set>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;
int x;

vi a;

set<int> b;

void input() {
  b.clear();

  cin >> n >> x;

  a.resize(n);
  for (auto&& i : a)
    cin >> i;
}

void solve() {
  for (auto&& i : a)
    b.insert(abs(i - x));

  int ans = *b.cbegin();

  for (auto&& i : b)
    ans = gcd(ans, i);

  cout << ans << '\n';
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
