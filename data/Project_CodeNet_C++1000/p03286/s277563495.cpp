#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  string ans = "";
  while (n != 0) {
    if (abs(n % 2) == 1) {
      ans += "1";
      if (n > 0) {
        n /= (-2);
      } else {
        n = (n - 1) / (-2);
      }
    } else {
      ans += "0";
      n /= (-2);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << (ans == "" ? "0" : ans) << endl;
  return 0;
}