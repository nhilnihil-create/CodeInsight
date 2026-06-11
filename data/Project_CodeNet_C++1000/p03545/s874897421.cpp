#include <iostream>
#include <string>
using namespace std;

int main() {
  string S(4, '0');
  cin >> S;
  int digit = S.size() - 1;
  for (int b = 0; b < (1 << digit); b++) {
    int res = S.at(0) - '0';
    string formula = to_string(res);
    for (int i = 0; i < digit; i++) {
      if (b & (1 << i)) {
        formula += '+';
        res += S.at(i + 1) - '0';
      } else {
        formula += '-';
        res -= S.at(i + 1) - '0';
      }
      formula += S.at(i + 1);
    }
    if (res == 7) {
      cout << formula + "=7" << endl;
      break;
    }
  }
}