#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdint>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, A, B; std::cin >> N >> A >> B;
  if(A+B-1 > N) fin(-1);
  if((int64_t)A*B < N) fin(-1);
  if(B==1) {
    for(int i = 1; i < N; ++i) std::cout << i << " ";
    fin(N);
  }
  int n = 0, k=0;
  while(k+1+N-n-B > A) {
    n += B; ++k;
    for(int i = n; i > n-B; --i) std::cout << i << " ";
  }
  int l = k+N-n-A+1;
  if(n+l == N) {
    for(int i = n+l; i > n+1; --i) std::cout << i << " ";
    fin(n+1);
  }
  for(int i = n+l; i > n; --i) std::cout << i << " ";
  for(int i = n+l+1; i < N; ++i) std::cout << i << " ";
  fin(N);
  return 0;
}
