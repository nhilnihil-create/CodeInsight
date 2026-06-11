#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main () {
  string ABCD;
  cin >> ABCD;
  for (int i = 0; i < 1 << 3; i++) {
    bitset<3> plus(i);
    vector<char> opt(3);
    int sum = (int)(ABCD.at(0) - '0');
    for (int j = 2; -1 < j; j--) {
      if (plus.test(j) & 1) {
        sum += (int)(ABCD.at(3 - j) - '0');
        opt.at(2 - j) = '+';
      }
      else {
        sum -= (int)(ABCD.at(3 - j) - '0');
        opt.at(2 - j) = '-';
      }
    }
    if (sum == 7) {
      cout << ABCD.at(0);
      for (int j = 0; j < 3; j++) {
        cout << opt.at(j);
        cout << ABCD.at(j + 1);
      }
      cout << "=7" << endl;
      break;
    }
  }
}
