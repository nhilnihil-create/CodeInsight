#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

string s;
string t;

void input() {
  cin >> s >> t;
}

void solve() {
  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());

  string ans = "No";

  if (s < t)
    ans = "Yes";

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

  _times = 5;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
