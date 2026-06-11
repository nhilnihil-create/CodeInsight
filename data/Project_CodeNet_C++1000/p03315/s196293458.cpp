#include <iostream>

using namespace std;

int main() {
  char c;
  int ans = 0;
  while (cin >> c) {
    if (c == '+')
      ++ans;
    else
      --ans;
  }
  cout << ans << endl;
}
