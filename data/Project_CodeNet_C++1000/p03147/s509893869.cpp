#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> h(n);
  int sum = 0;
  rep(i, n) {
    std::cin >> h[i];
    sum += h[i];
  }

  int num = 0;
  rep(i, n - 1) {
    if (h[i] > h[i + 1]) {
      num += h[i] - h[i + 1];
    }
  }
  num += h[n - 1];

  std::cout << num << std::endl;
  return 0;
}
