#include <iostream>
#include <string>

std::string StringRotation(std::string s);

int main() {
  std::string S, T;
  std::cin >> S >> T;

  bool flag{false};
  // A string S returns to its original state after N rotations, N = S.length()
  for (int i = 0; i < S.length(); i++) {
    S = StringRotation(S);
    if (S == T) {
      flag = true;
      break;
    }
  }

  if (flag)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}

std::string StringRotation(std::string s) {
  // "abc" -> 'c' + "ab" -> "cab"
  return s.back() + s.substr(0, s.length() - 1);
}
