#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> b(n), w(n);
  if (s[0] == '#')
    b[0] = 1;
  else
    w[0] = 1;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == '#')
      b[i] = b[i - 1] + 1, w[i] = w[i - 1];
    else
      b[i] = b[i - 1], w[i] = w[i - 1] + 1;
  }

  int sum_w = w.back();
  int ans = sum_w;
  for (int i = 0; i < s.size(); ++i) {
    ans = min(ans, b[i] + sum_w - w[i]);
  }
  cout << ans << endl;
}