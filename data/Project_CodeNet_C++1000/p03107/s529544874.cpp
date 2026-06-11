#include <iostream>
#include <string>
using namespace std;

int main() {
  int cnt = 0, len;
  string s;
  cin >> s;
  len = s.size();
  for (int i = 0; i < len - 1; i++) {
    if (i == -1) i = 0;
    if ((s[i] == '0' && s[i + 1] == '1') || (s[i] == '1' && s[i + 1] == '0')) {
      cnt += 2;
      s.erase(i, 2);
      len = s.size();
      i -= 2;
    }
  }
  cout << cnt << endl;
}