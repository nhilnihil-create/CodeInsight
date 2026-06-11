#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, m;
  std::cin >> n >> m;
  std::map<int, int> map;
  rep(i, n) {
    int k;
    std::cin >> k;
    rep(i, k) {
      int a;
      std::cin >> a;
      map[a]++;
    }
  }

  int sum = 0;
  for (auto i : map) {
    if (i.second == n) {
      sum++;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}
