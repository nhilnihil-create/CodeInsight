#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <map>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;
map<int, int> a;

int m;

void input() {
  a.clear();

  cin >> n;

  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;

    a[t]++;
  }
  
  cin >> m;
}

void solve() {
  string ans = "YES";

  while (m--) {
    int t;
    cin >> t;

    a[t]--;

    if (a[t] < 0)
      ans = "NO";
  }
  
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

  _times = 4;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
