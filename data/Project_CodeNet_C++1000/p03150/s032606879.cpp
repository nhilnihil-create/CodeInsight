#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s, key = "keyence";
  cin >> s;

  int n = s.size(), i = 0, now = 0;

  while (s[i] == key[now]) {
    if (now == 6) {
      cout << "YES" << endl;
      return 0;
    } else {
      i++;
      now++;
    }
  }

  if (s.substr(n - 7 + i) == key.substr(now))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}