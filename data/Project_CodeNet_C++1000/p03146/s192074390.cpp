#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  vector<bool> done(10000000, false);
  int cnt = 0;
  while (true) {
    cnt++;
    if (done.at(s)) {
      cout << cnt << endl;
      break;
    }
    else {
      done.at(s) = true;
      if (s % 2 == 0) {
        s /= 2;
      }
      else {
        s = 3 * s + 1;
      }
    }
  }
}
