
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  vector<int> a(26, 0);
  vector<int> b(26, 0);

  for (int i = 0; i < s.size(); i++) {
    int c = s.at(i) - 'a';
    a.at(c)++;
  }
  for (int i = 0; i < t.size(); i++) {
    int c = t.at(i) - 'a';
    b.at(c)++;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < 26; i++) {
    if (a.at(i) != b.at(i)) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}