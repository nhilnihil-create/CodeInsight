#include<iostream>
#include<map>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

void make_map(std::map<std::string, int64_t>& m, char const* str, int N) {
  for(int s = 0; s < (1<<N); ++s) {
    std::string S, T;
    for(int i = 0; i < N; ++i) {
      if((1<<i)&s) S += str[i];
      else         T += str[i];
    }
    ++m[S+' '+T];
  }
}

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);

  int N; std::string S; std::cin >> N >> S;
  char buf[18];
  for(int i = 0; i < N; ++i) buf[i] = S[N+N-1-i];
  std::map<std::string, int64_t> m1, m2;
  make_map(m1, S.c_str(), N);
  make_map(m2, buf, N);
  int64_t ans = 0;
  for(auto const& p: m1) if(m2.count(p.first) > 0) {
    ans += p.second * m2[p.first];
  }
  fin(ans);
  return 0;
}
