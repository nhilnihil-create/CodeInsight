#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

char preback (const string &s) {
  return *next(s.rbegin());
}

int main () {
  string s;
  cin >> s;

  if ((int) s.size() == 26) {
    if (s == string("zyxwvutsrqponmlkjihgfedcba")) {
      cout << -1 << endl;
    } else {
      set<char> dels;
      while (dels.upper_bound(s.back()) == dels.end()) {
        dels.insert(s.back());
        s.pop_back();
      }

      char add = *dels.upper_bound(s.back());
      s.pop_back();
      cout << s << add << endl;
    }
  } else {
    set<char> unseen;
    for (char c = 'a'; c <= 'z'; c++) {
      unseen.insert(c);
    }
    for (char c : s) {
      unseen.erase(c);
    }
    cout << s << *unseen.begin() << '\n';
  }
}
