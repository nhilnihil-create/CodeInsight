#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  long long answer = 0;
  int current = 0;
  for (auto c : s) {
    if (c == 'B') {
      ++current;
    } else {
      answer += current;
    }
  }
  cout << answer << endl;
  return 0;
}