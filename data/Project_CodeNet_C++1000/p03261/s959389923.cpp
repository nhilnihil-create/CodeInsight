#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::vector<std::string> vs;
  for (int i = 0; i < n; ++i) {
    std::cin >> s;
    vs.push_back(s);
  }

  bool flag = true;
  std::string temp = vs[0];
  for (int i = 1; i < n; ++i) {
    if (vs[i].front() != vs[i-1].back()) {
      flag = false;
      break;
    }
  }

  for (int j = 1; j < n; ++j) {
    for (int k = 0; k < n; ++k) {
      if (j != k && vs[j] == vs[k]) {
        flag = false;
      }
    }
  }

  if (flag) {
    puts("Yes");
  }
  else {
    puts("No");
  }

  return 0;
}