#include <bits/stdc++.h>
#include <functional>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int64_t n, x;
  std::cin >> n >> x;
  std::vector<int64_t> a(n);
  rep(i, n) std::cin >> a[i];

  sort(a.begin(), a.end());
  int ans = 0;
  rep(i, n) {
    if (a[i] <= x) {
      x -= a[i];
      ans++;
    } else {
      break;
    }
  }

  if (ans == n && x > 0) {
    ans--;
  }

  std::cout << ans << std::endl;
  return 0;
}
