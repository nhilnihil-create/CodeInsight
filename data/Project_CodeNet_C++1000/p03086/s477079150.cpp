#include <iostream>

using namespace std;

int main() {
  int ans = 0;
  int cnt = 0;
  char c;
  while (cin >> c) {
    if (c == 'A' || c == 'C' || c == 'G' || c == 'T')
      ++cnt;
    else
      cnt = 0;
    ans = max(cnt, ans);
  }
  cout << ans << endl;
}
