#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() == 2) {
    cout << s << '\n';
  } else {
    for (int i = 2; i >= 0; --i) cout << s[i];
    cout << '\n';
  }
  return 0;
}
