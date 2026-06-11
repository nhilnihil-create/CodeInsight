#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '2') {
      ans++;
    }
  }

  cout << ans << '\n';
}