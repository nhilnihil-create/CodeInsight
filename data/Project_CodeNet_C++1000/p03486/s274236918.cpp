#include <bits/stdc++.h>
#include <functional>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s, t;
  std::cin >> s >> t;

  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());
  if (s < t) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
