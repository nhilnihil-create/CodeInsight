#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
  std::string s;
  std::cin >> s;
  std::vector<unsigned long long> xo(s.size() + 1, 0);
  for (unsigned i = 1; i <= s.size(); ++i) {
    xo[i] = xo[i - 1] ^ (1ull << (unsigned) (s[i - 1] - 'a'));
  }
  std::unordered_map<unsigned long long, unsigned> map;
  for (auto i = s.size() + 1; i-- > 0;) {
    if (map.find(xo[i]) != map.end()) {
      map.find(xo[i])->second = (unsigned int) i;
    } else {
      map.emplace(xo[i], i);
    }
  }
  std::vector<unsigned long long> dp(s.size() + 1, 0);
  for (unsigned i = 1; i <= s.size(); ++i) {
    auto aa = map.find(xo[i]);
    if (aa == map.end()) {
      map.emplace(xo[i], i);
      aa = map.find(xo[i]);
    }
    auto a = aa->second;
    if (a >= i) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = std::min(dp[i - 1] + 1, dp[a] + 1);
    }
    for (auto c = 0u; c < (unsigned) ('z' - 'a' + 1); ++c) {
      auto bb = map.find(xo[i] ^ (1ull << c));
      if (bb == map.end()) { continue; }
      auto b = bb->second;
      if (b >= i) { continue; }
      dp[i] = std::min(dp[i], dp[b] + 1);
    }
    if (dp[map.find(xo[i])->second] > dp[i]) {
      map.find(xo[i])->second = i;
    }
  }
  std::cout << dp.back() << std::endl;
  return 0;
}