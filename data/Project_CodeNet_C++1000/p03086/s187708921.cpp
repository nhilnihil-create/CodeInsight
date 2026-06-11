#include <bits/stdc++.h>
using namespace std;

set<char> ACGT{'A', 'C', 'G', 'T'};

int main() {
  string S;
  cin >> S;
  int ans{}, len{};
  for (const char &c : S) {
    if (ACGT.find(c) != ACGT.end()) {
      ++len;
    } else {
      ans = max(ans, len);
      len = 0;
    }
  }
  ans = max(ans, len);

  cout << ans << endl;
  return 0;
}
