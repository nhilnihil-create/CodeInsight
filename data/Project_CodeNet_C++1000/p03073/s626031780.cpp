#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int a = 0;
  int b = 0;
  for (int i = 0; i <= static_cast<int>(s.size()); ++i) {
    a += (i % 2 == 0 && s[i] == '0') || (i % 2 == 1 && s[i] == '1');
    b += (i % 2 == 0 && s[i] == '1') || (i % 2 == 1 && s[i] == '0');
  }
  cout << min(a, b) << endl;
}