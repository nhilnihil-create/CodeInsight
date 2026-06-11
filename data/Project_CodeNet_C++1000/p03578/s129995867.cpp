#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, m;
  std::cin >> n;
  std::map<int64_t, int64_t> md;
  std::map<int64_t, int64_t> mt;
  std::vector<uint64_t> d(n);
  rep(i, n) {
    std::cin >> d[i];
    md[d[i]]++;
  }
  std::cin >> m;
  std::vector<uint64_t> t(m);
  rep(i, m) {
    std::cin >> t[i];
    mt[t[i]]++;
  }

  for (auto i : mt) {
    if (md[i.first] - i.second < 0) {
      std::cout << "NO" << std::endl;
      return 0;
    }
  }

  std::cout << "YES" << std::endl;
  return 0;
}
