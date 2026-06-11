#include <bits/stdc++.h>
using namespace std;

int main() {
  string top;
  cin >> top;
  int res = 700;
  for (int i = 0; i < 3; i++) {
    if (top.at(i) == 'o') {
      res += 100;
    }
  }
  cout << res << endl;
}
