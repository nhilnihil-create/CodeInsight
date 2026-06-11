#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, M; std::cin >> N >> M;
  std::vector<std::pair<int64_t, int>> p(N+M);
  for(int i = 0; i < N; ++i) {
    std::cin >> p[i].first;
    p[i].second = 1;
  }
  for(int i = 0; i < M; ++i) std::cin >> p[N+i].second >> p[N+i].first;
  std::sort(p.begin(), p.end(), std::greater<std::pair<int64_t,int>>());
  int count = 0;
  int64_t ans = 0;
  for(auto const& v: p) {
    if(count + v.second <= N) {
      ans += v.first*v.second;
      count += v.second;
    } else {
      ans += v.first*(N-count);
      fin(ans);
    }
  }
  return 0;
}
