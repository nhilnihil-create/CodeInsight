#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

int main()
{
  int N, M;
  std::cin >> N >> M;
  std::vector<int> foods(M);

  for(int i=0; i<N; i++) {
    int K;
    std::cin >> K;
    for(int j=0; j<K; j++) {
      int f;
      std::cin >> f;
      f--;  // 0 origin
      foods[f]++;
    }
  }
  // print_container(foods, "foods");

  int ret = 0;
  for(int i=0; i<M; i++) {
    if(foods[i] == N) ret++;
  }
  std::cout << ret << std::endl;

  return 0;
}
