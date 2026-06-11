#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  string t;

  int count_A = 0;
  int64_t answer = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') {
      count_A++;
    } else if (i + 1 < s.length() && s[i] == 'B' && s[i + 1] == 'C') {
      answer += count_A;
      i++;
    } else {
      count_A = 0;
    }
  }

  cout << answer << endl;

  return 0;
}
