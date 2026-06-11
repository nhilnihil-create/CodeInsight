#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
#include <vector>

template <typename Container, class T>
bool contains(const Container& c, T v)
{
  return std::find(c.begin(), c.end(), v) != c.end();
}

int main()
{
  int M, K;
  std::cin >> M >> K;

  if(std::pow(2, M) <= K) {
    std::cout << -1 << std::endl;
    return 0;
  }
  if(M==1 && K==1) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::vector<int> ret2;
  ret2.assign(std::pow(2, M), -1);

  // K in the middle
  int j = ret2.size() - 1;
  ret2[j] = K;
  j--;

  // let K sandwitched between i and K^i
  int max_i = std::pow(2, M);

  for(int i=0; i<max_i; i++) {
    if(i == K || (K^i) < i) continue;

    // std::cout << "i = " << i
    //           << "K^i = "  << (K^i)
    //           << std::endl;

    ret2[j] = i;
    j--;

    if((K^i) == K || (K^i) == i) continue;
    ret2[j] = K^i;
    j--;
  }
  // std::cout << "j: " << j << std::endl;

  for(auto &c: ret2) {
    std::cout << c << " ";
  }
  if(K==0) {
    std::cout << K << " ";
  }
  for(auto it=ret2.rbegin() + 1; it !=ret2.rend(); it++) {
    std::cout << *it << " ";
  }
  if(K!=0) {
    std::cout << K << " ";
  }

  std::cout << std::endl;

  return 0;
}
