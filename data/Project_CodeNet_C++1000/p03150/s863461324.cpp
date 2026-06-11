#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  cin >> s;
  bool res = 0;
  for (int i = 0; i <= 7; ++i) {
    string t;
    for (int j = 0; j < i; ++j) t += s[j];
    for (int j = i; j < 7; ++j) t += s[s.size() - 7 + j];
    if (t == "keyence") res = 1;
  }
  if (res)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
