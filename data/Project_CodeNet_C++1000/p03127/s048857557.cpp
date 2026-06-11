#include <algorithm>
#include <iostream>
#include <vector>

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

int get_GCD(int lhs, int rhs)
{
  int a = std::max(std::abs(lhs), std::abs(rhs));
  int b = std::min(std::abs(lhs), std::abs(rhs));

  if(b == 0) return 1;

  int res = a % b;

  while(res != 0) {
    a = b;
    b = res;
    res = a % b;
  }
  return b;
}

int get_GCD(const std::vector<int> &invec)
{
  std::vector<int> vec(invec);
  auto len = vec.size();
  while(len != 1) {
    // print_container(vec, "vec" + std::to_string(len));
    std::vector<int> gcds((len + 1)/2);

    for(size_t i=0; i<len/2; i++) {
      gcds[i] = get_GCD(vec[2*i], vec[2*i+1]);
    }
    if(len % 2 == 1) {
      gcds[len/2] = vec[len-1];
    }
    vec = gcds;
    len = vec.size();
  }

  return vec[0];
}

int main()
{
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for(int i=0; i<N; i++) {
    std::cin >> A[i];
  }

  std::cout << get_GCD(A) << std::endl;

  return 0;
}
