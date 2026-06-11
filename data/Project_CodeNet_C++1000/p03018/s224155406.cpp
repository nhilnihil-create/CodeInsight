#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  int n = s.size();
  string t;
  for (int i = 0; i < n; ++i) {
    if (i < (n - 1) && s[i] == 'B' && s[i + 1] == 'C') {
      t += 'D';
      ++i;
    } else {
      t += s[i];
    }
  }
  // cout << t << endl;

  n = t.size();
  int64_t answer = 0;
  int64_t count = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i] == 'A') {
      count++;
    } else if (t[i] == 'D') {
      answer += count;
    } else {
      count = 0;
    }
  }
  cout << answer << endl;
  return 0;
}