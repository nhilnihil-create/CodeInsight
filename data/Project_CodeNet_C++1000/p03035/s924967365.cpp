#include<iostream>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int A, B; std::cin >> A >> B;
  if(A <= 5) fin(0);
  if(A >= 13) fin(B);
  fin(B/2);
  return 0;
}
