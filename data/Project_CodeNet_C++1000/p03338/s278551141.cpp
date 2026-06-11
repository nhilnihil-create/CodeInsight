#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  map<char, int> b;
  int m = 0;
  for (int i = 1; i < n - 1; i++) {
    string sl = s.substr(0, i);
    string sr = s.substr(i);
    b.clear();
    for (int i = 0; i < sl.size(); i++) {
      char c = sl[i];
      if (sr.find(c) != string::npos) {
        if (b.find(c) == b.end()) {
          b[c] = 0;
        } else {
          b[c]++;
        }
      }
    }
    m = max(m, (int)b.size());
  }
  cout << m << endl;
  return 0;
}
