#include <iostream>
#include <string>
#include <vector>

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> s(h);
  for (int i = 0; i < h; i++) {
    std::cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        if (i == 0) {
          if (j == 0 && s[i + 1][j] == '.' && s[i][j + 1] == '.') {
            std::cout << "No" << "\n";
            return 0;
          } else if (j == w - 1 && s[i + 1][j] == '.' && s[i][j - 1] == '.') {
            std::cout << "No" << "\n";
            return 0;
          }
        } else if (i == h - 1) {
          if (j == 0 && s[i - 1][j] == '.' && s[i][j + 1] == '.') {
            std::cout << "No" << "\n";
            return 0;
          } else if (j == w - 1 && s[i - 1][j] == '.' && s[i][j - 1] == '.') {
            std::cout << "No" << "\n";
            return 0;
          }
        } else if (j == 0) {
          if (s[i][j + 1] == '.' && s[i - 1][j] == '.' && s[i + 1][j] == '.') {
            std::cout << "No" << "\n";
            return 0;
          }
        } else if (j == w - 1) {
          if (s[i][j - 1] == '.' && s[i - 1][j] == '.' && s[i + 1][j] == '.') {
            std::cout << "No" << "\n";
            return 0;
          }
        } else {
          if (s[i][j + 1] == '.' && s[i][j - 1] == '.' && s[i - 1][j] == '.' && s[i + 1][j] == '.') {
            std::cout << "No" << "\n";
            return 0;
          }
        }
      }
    }
  }
  std::cout << "Yes" << "\n";
  return 0;
}