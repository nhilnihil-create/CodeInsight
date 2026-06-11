#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  for (int b = 0; b < (1 << 3); ++b) {
    int total = S[0] - '0';
    string f = string(1, S[0]);
    for (int i = 0; i < 3; ++i) {
      int n = S[i + 1] - '0';
      if (b & (1 << i)) total += n, f += '+';
      else total -= n, f += '-';
      f += S[i + 1];
    }
    f = f + '=' + to_string(total);

    if (total == 7) {
      cout << f << endl;
      break;
    }
  }
}