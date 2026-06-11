#include <bits/stdc++.h>

int main() {
  int a, b;
  std::cin >> a >> b;
  a--;
  b--;
  int count = std::min(a, b) / 50;

  std::string stripe1(100, '.');
  for (int i = 0; i < 100; i++) {
    if (i % 2 == 1) {
      stripe1[i] = '#';
    }
  }
  std::string stripe2(100, '.');
  for (int i = 0; i < 100; i++) {
    if (i % 2 == 0) {
      stripe2[i] = '#';
    }
  }

  std::vector<std::string> ans;
  ans.reserve(100);
  a -= count * 50;
  b -= count * 50;
  ans.push_back(std::string(100, '.'));
  while (50 < b) {
    ans.push_back(stripe1);
    ans.push_back(std::string(100, '.'));
    b -= 50;
  }
  if (b != 0) {
    std::string s(100, '.');
    for (int i = 0; i < 99; i++) {
      if (i % 2 == 1 && 0 < b) {
        s[i] = '#';
        b--;
      }
    }
    ans.push_back(std::move(s));
    ans.push_back(std::string(100, '.'));
  }

  ans.push_back(stripe1);
  for (int i = 1; i <= count; i++) {
    if (i % 2 == 1) {
      ans.push_back(stripe2);
    } else {
      ans.push_back(stripe1);
    }
  }

  ans.push_back(std::string(100, '#'));
  while (50 < a) {
    ans.push_back(stripe1);
    ans.push_back(std::string(100, '#'));
    a -= 50;
  }
  if (a != 0) {
    std::string s(100, '#');
    for (int i = 0; i < 99; i++) {
      if (i % 2 == 1 && 0 < a) {
        s[i] = '.';
        a--;
      }
    }
    ans.push_back(std::move(s));
    ans.push_back(std::string(100, '#'));
  }

  std::cout << ans.size() << " " << 100 << std::endl;
  for (const auto &i : ans) {
    std::cout << i << std::endl;
  }
  return 0;
}
