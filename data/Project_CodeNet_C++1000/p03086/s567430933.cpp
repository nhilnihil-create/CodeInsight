#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;
  int maxv = 0;
  for (int i = 0; i < s.length(); ++i) {
    int count = 0;
    while (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
      count++;
      i++;
    }
    maxv = max(maxv, count);
  }
  std::cout << maxv << std::endl;
  return 0;
}
