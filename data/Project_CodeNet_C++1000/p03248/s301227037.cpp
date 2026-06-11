#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  s = '0' + s;
  if (s[1] != '1')
    return cout << "-1\n", 0;
  for (int i = 0; i <= (n - 1) / 2; ++i)
    if (s[i] != s[n - i])
      return cout << "-1\n", 0;
  vector<int> v;
  for (int i = 1; i <= n / 2; ++i)
    if (s[i] == '1') v.push_back(i);
  int tot = (int)v.size();
  for (int i = 0; i < (int)v.size() - 1; ++i) {
    cout << i + 1 << ' ' << i + 2 << '\n';
    for (int j = 0; j < v[i + 1] - v[i] - 1; ++j)
      cout << ++tot << ' ' << i + 2 << '\n';
  }
  cout << (int)v.size() << ' ' << n << '\n';
  for (int i = tot + 1; i < n; ++i)
    cout << i << ' ' << n << '\n';
  return 0;
}
