#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  string answer = "No";
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  if (s.size() < t.size() && s == t.substr(0, s.size())) answer = "Yes";
  for (int i = 0; i < min(s.size(), t.size()); i++) {
    if ((s[i] > t[i])) break;
    if (s[i] < t[i]) answer = "Yes";
  }
  cout << answer;
}