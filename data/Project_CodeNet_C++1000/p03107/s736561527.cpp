#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int result = 0;
  size_t i = 0;
  while (i + 1 < S.size()) {
    if ((0 == S.compare(i , 2, "01")) ||
        (0 == S.compare(i , 2, "10"))) {
      S.erase(i, 2);
      result += 2;
      if (0 < i) --i;
    } else {
      ++i;
    }
  }
  cout << result << endl;
  return 0;
}
