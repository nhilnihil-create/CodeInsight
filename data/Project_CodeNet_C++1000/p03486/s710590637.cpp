#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());

  string result = s < t ? "Yes" : "No";
  cout << result << endl;
  return 0;
}