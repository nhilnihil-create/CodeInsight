#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s;
  vector<int> v{0};
  for (int i = 0, n = s.size(); i != n; ++i) {
    if (s[i] != 'x')
      t.push_back(s[i]), v.emplace_back();
    else
      ++v.back();
  }
  if (!equal(begin(t), end(t), rbegin(t))) {
    cout << -1 << endl;
    return 0;
  }

  int ans{};
  for (int i = 0, n = v.size(); i != n / 2; ++i) {
    ans += abs(v[i] - v[n - i - 1]);
  }
  cout << ans << endl;
}
