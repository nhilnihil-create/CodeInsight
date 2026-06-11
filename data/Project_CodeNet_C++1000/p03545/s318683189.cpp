#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  string ans = "";
  for (int b = 0; b < (1 << 3); b++) {
    int res = S.at(0) - '0';
    string formula = to_string(res);
    for (int i = 0; i < S.size() - 1; i++) {
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
