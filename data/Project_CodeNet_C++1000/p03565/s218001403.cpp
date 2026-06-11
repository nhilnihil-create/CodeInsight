#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int p = -1;
  for (int i = 0; i < int(s.size()) - int(t.size()) + 1; ++i) {
    int cnt = 0;
    for (int j = 0; j < int(t.size()); ++j)
      cnt += s[i+j] == '?' || s[i+j] == t[j];
    if (cnt == int(t.size()))
      p = i;
  }

  if (p == -1) {
    cout << "UNRESTORABLE" << endl;
  } else {
    for (int i = 0; i < p; ++i)
      cout << (s[i] == '?' ? 'a' : s[i]);
    cout << t;
    for (int i = p + int(t.size()); i < int(s.size()); ++i)
      cout << (s[i] == '?' ? 'a' : s[i]);
    cout << endl;
  }
}