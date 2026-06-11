#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

template <typename Map>
void print_map(const Map &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.begin(), c.end(),
                [](auto &x) { std::cout << x.first << "->" << x.second << ", "; });
  std::cout << std::endl;
}

int main()
{
  uint64_t N, M;
  std::cin >> N >> M;
  std::vector<uint64_t> A(N);
  std::vector<uint64_t> integrate(N);
  std::map<int, int> mod_num;

  std::cin >> A[0];
  integrate[0] = A[0] % M;
  mod_num[integrate[0]]++;

  for(uint64_t i=1; i<N; i++) {
    std::cin >> A[i];
    integrate[i] = (integrate[i-1] + A[i]) % M;
    mod_num[integrate[i]]++;
  }
  // print_container(integrate, "integrate");
  // print_map(mod_num, "mod_num");

  uint64_t minus = 0;
  uint64_t ret = mod_num[0];
  for(uint64_t l=1; l<N; l++) {
    minus = (minus + A[l-1]) % M;
    mod_num[minus]--;

    // std::cout << "l: " << l << "minus: " << minus << std::endl;
    // print_map(mod_num, "mod_num");

    ret += mod_num[minus];
  }

  std::cout << ret << std::endl;

  return 0;
}
