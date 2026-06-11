#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int num;
  int res = 10000000;
  for (int i = 0; i <= (int)s.size() - 3; i++) {
    num = (s.at(i) - '0') * 100 + (s.at(i + 1) - '0') * 10 + (s.at(i + 2) - '0');
    res = min(res, abs(num - 753));
  }
  cout << res << endl;
}



