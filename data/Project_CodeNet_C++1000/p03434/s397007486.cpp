#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  rep(i, n) { std::cin >> a[i]; }

  sort(a.begin(), a.end(), std::greater<int>());
  int ans = 0;
  rep(i, n) {
    ans += a[i] - a[i+1];
    ++i;
  }

  std::cout << ans << std::endl;
  return 0;
}
