#include <iostream>
#include <string>

using namespace std;

int main () {
  string s;
  cin >> s;

  int ans = s[0] - '1';
  ans += 9 * ((int) s.size() - 1);

  int dans = 0;
  for (char c : s) {
    dans += c - '0';
  }
  
  cout << max(ans, dans) << endl;
}
