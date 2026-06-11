#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, r = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') ++r;
  }
  if (r > n - r) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}