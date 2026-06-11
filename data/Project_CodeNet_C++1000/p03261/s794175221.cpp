#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  string last; cin >> last;
  unordered_set<string> s;
  s.insert(last);
  bool w = true;
  for (int i = 1; i < n; ++i) {
    string cur; cin >> cur;
    if (s.find(cur) != s.end()) {
      w = false;
    }
    if (cur[0] != last[last.length()-1]) w = false;
    s.insert(cur);
    last = cur;
  }
  cout << (w ? "Yes" : "No") << endl;
}
