#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;

  int ans{753};
  for (size_t i = 0; i != S.size() - 2; ++i) {
    ans = min(ans, abs(753 - stoi(S.substr(i, 3))));
  }

  cout << ans << endl;

  return 0;
}
