#include<iostream>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int A, P; std::cin >> A >> P;
  P += A*3;
  fin(P/2);
  return 0;
}