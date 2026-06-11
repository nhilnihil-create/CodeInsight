#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, d, x;
  std::cin >> n >> d >> x;
  std::vector<int> a(n);
  rep(i, n) std::cin >> a[i];

  rep(j, n) {
    int i = 0;
    while(d >= i * a[j] + 1) {
      i++;
      x++;
    }
  }

  std::cout << x << std::endl;
  return 0;
}
