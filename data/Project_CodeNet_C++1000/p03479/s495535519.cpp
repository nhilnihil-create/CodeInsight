#include<iostream>
#include<cstdint>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int64_t X, Y; std::cin >> X >> Y;
  int ans = 1;
  while(X*2 <= Y){
    ++ans;
    X*=2;
  }
  fin(ans);
  return 0;
}
