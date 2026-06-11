#include <bits/stdc++.h>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;

  s += '0';

  int minv = 1000;
  for (int i = 1; i < s.size() - 2; ++i) {
    minv = min(minv, abs(stoi(s.substr(i - 1, 3)) - 753));
  }

  std::cout << minv << std::endl;
  return 0;
}
