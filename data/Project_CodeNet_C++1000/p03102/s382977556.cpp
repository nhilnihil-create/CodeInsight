#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, m, c;
  std::cin >> n >> m >> c;
  std::vector<int> b(m);
  std::vector<int> code(n);
  rep(i, m) std::cin >> b[i];
  rep(i, n) {
    rep(j, m) {
      int x = 0;
      std::cin >> x;
      code[i] += x * b[j];
    }
    code[i] += c;
  }

  int ans = 0;
  rep(i, n) {
    if (code[i] > 0) {
      ans++;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
