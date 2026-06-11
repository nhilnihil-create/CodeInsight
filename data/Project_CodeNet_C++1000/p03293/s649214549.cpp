#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  
  bool bo = false;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (s.at((i + j) % s.size()) != t.at(j)) {
        break;
      }
      else if (j == s.size() - 1) {
        bo = true;
      }
    }
    if (bo) {
      break;
    }
  }
  if (bo) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}