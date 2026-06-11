#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 0, end_with_a = 0, begin_with_b = 0,
      begin_with_a_and_end_with_b = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size() - 1; ++j) {
      if (s[j] == 'A' && s[j + 1] == 'B')
        ++ans;
    }
    if (s.back() == 'A' && s.front() == 'B')
      ++begin_with_a_and_end_with_b;
    else if (s.back() == 'A')
      ++end_with_a;
    else if (s.front() == 'B')
      ++begin_with_b;
  }

  ans += min(end_with_a, begin_with_b);
  ans += begin_with_a_and_end_with_b;
  if (end_with_a + begin_with_b == 0 && begin_with_a_and_end_with_b > 0)
    ans -= 1;
  cout << ans << endl;
}