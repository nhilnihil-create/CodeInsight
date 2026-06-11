#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string S;
  cin >> S;
  bool pred = S[0] == 'A' && count(begin(S) + 2, end(S) - 1, 'C') == 1 &&
              all_of(begin(S) + 1, end(S),
                     [](char c) { return (c >= 'a' && c <= 'z') || c == 'C'; });
  cout << (pred ? "AC" : "WA") << endl;

  return 0;
}
