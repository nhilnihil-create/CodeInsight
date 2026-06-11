#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string S;
  std::cin >> S;

  int f = 0, m = 0;
  for (int i = 0; i < S.size(); i++) {
    auto c = S[i];
    if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
      f++;
    } else {
      f = 0;
    }
    m = std::max(f, m);
  }

  std::cout << m << std::endl;

  return 0;
}
