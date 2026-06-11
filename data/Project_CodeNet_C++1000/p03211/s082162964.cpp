#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int min_value = 100000000;
  for (int i = 2; i < S.size(); ++i) {
    int A, B, C;
    A = S.at(i - 2) - '1' + 1;
    B = S.at(i - 1) - '1' + 1;
    C = S.at(i) - '1' + 1;
    int value = A * 100 + B * 10 + C * 1;
    min_value = min(min_value, abs(value - 753));
  }

  cout << min_value << endl;
  return 0;
}
