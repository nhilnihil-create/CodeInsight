#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <numeric>

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

int main()
{
  int N, M;
  std::cin >> N >> M;
  std::vector<uint64_t> A(N), B(M), C(M);
  for(int i=0; i<N; i++) {
    std::cin >> A[i];
  }
  for(int i=0; i<M; i++) {
    std::cin >> B[i] >> C[i];
  }

  std::sort(A.begin(), A.end(), std::less<int>());
  std::vector<size_t> argsort(M);
  for(int i=0; i<M; i++) {
    argsort[i] = i;
  }

  // argsort C
  std::sort(argsort.begin(), argsort.end(),
            [&C](auto lhs, auto rhs) -> bool {
              return C[lhs] > C[rhs];
            });
  // print_container(argsort, "argsort");

  size_t j = 0;
  bool do_fin = false;
  for(size_t i : argsort) {
    uint64_t b = B[i];
    uint64_t c = C[i];
    uint64_t n_replaced = 0;

    while(j<N) {
      // std::cout << "j: " << j << std::endl;
      if(A[j] >= c) {
        do_fin = true;
        break;
      }

      A[j] = c;
      n_replaced++;
      j++;

      if(n_replaced == b) break;
    }

    if(do_fin) break;
  }

  // print_container(A, "A");
  uint64_t sum = std::accumulate(A.begin(), A.end(), 0ULL);

  std::cout << sum << std::endl;
  return 0;
}
