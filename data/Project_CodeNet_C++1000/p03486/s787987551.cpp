#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  vector<char> a(s.size());
  vector<char> b(t.size());
  for (int i = 0; i < s.size(); i++) {
    a.at(i) = s.at(i);
  }
  for (int i = 0; i < t.size(); i++) {
    b.at(i) = t.at(i);
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  
  bool x = false;
  if (a.size() < b.size()) {
    bool y = true;
    for (int i = 0; i < a.size(); i++) {
      if (a.at(i) != b.at(i)) y = false;
    }
    x = y;
  }
  for (int i = 0; i < min(a.size(), b.size()); i++) {
    if (a.at(i) != b.at(i)) {
      if (a.at(i) < b.at(i)) x = true;
      break;
    }
  }
  
  if (x) cout << "Yes" << endl;
  else cout << "No" << endl;
}