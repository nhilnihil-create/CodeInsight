#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdint>
#include<cassert>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N;  std::cin >> N;
  std::vector<std::pair<int,int>> AB(N);
  for(int i = 0; i < N; ++i) std::cin >> AB[i].first >> AB[i].second;
  int64_t ans = 0, cur;
  auto reduce = [&]()->int64_t {
    std::sort(AB.begin(), AB.end(),
      [&](auto const& l, auto const& r){ return l.first-l.second < r.first-r.second; });
    if(AB.front().first==AB.front().second && AB.back().first==AB.back().second) return 0;
    int64_t sum = 0;
    int i = 0;
    while(AB[i].first <= AB[i].second) {
      sum += AB[i].second;
      ++i;
    }
    for(int j = 0; j+i < AB.size() ; ++j) AB[j] = AB[j+i];
    AB.resize(AB.size() - i);
    std::sort(AB.begin(), AB.end(),
      [&](auto const& l, auto const& r){ return l.second > r.second; });
    for(auto& p: AB) p.first = p.second;
    --AB.front().first;
    ++AB.back().first;
    return sum;
  };
  while((cur = reduce()) > 0) ans += cur;
  fin(ans);
  return 0;
}
