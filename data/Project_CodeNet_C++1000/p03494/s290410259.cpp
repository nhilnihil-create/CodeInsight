#include <bits/stdc++.h>
#include <cstdint>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<uint64_t> a(n);
  rep(i, n) std::cin >> a[i];

  int i = 0;
  bool ok = true;
  while (ok) {
    rep(i, n) {
      if (a[i] % 2 != 0) {
        ok = false;
        break;
      }
      a[i] /= 2;
    }
    i++;
  }

  std::cout << i - 1 << std::endl;
  return 0;
}
