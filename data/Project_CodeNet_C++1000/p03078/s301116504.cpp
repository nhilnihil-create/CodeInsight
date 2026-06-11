#include <algorithm>
#include <functional>
#include <iostream>
#include <set>

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

template <typename Map>
void chomp(Map &x, uint64_t k)
{
  auto it = x.begin();
  uint64_t i = 0;
  uint64_t min = *x.begin();
  while(it != x.end()) {
    if(k <= i && *it != min) {
      it = x.erase(it);
    } else {
      min = *it;
      it++;
    }
    i++;
  }
}

int main()
{
  uint64_t X, Y, Z, K;
  std::cin >> X >> Y >> Z >> K;
  std::multiset<uint64_t, std::greater<uint64_t> > A, B, C;
  for(uint64_t i=0; i<X; i++) {
    uint64_t t; std::cin >> t;
    A.insert(t);
  }
  for(uint64_t i=0; i<Y; i++) {
    uint64_t t; std::cin >> t;
    B.insert(t);
  }
  for(uint64_t i=0; i<Z; i++) {
    uint64_t t; std::cin >> t;
    C.insert(t);
  }

  // chmop after K-element
  chomp(A, K);
  // print_container(A, "A");
  chomp(B, K);
  // print_container(B, "B");
  chomp(C, K);
  // print_container(C, "C");

  // calc A+B top-K
  std::multiset<uint64_t, std::greater<uint64_t> > AB;
  uint64_t min = *A.begin() + *B.begin();
  for(auto a: A) {
    for(auto b: B) {
      auto ab = a + b;
      if(AB.size() < K) {
        AB.insert(ab);
        min = *AB.rbegin();
      } else if(min < ab) {
        AB.erase(--AB.end());
        AB.insert(ab);
        min = *AB.rbegin();
      }
    }
  }
  // print_container(AB, "AB");

  std::multiset<uint64_t, std::greater<uint64_t> > ABC;
  min = *AB.begin() + * C.begin();
  for(auto ab: AB) {
    for(auto c: C) {
      auto abc = ab + c;
      if(ABC.size() < K) {
        ABC.insert(abc);
        min = *ABC.rbegin();
      } else if(min < abc) {
        ABC.erase(--ABC.end());
        ABC.insert(abc);
        min = *ABC.rbegin();
      }
    }
  }
  // print_container(ABC, "ABC");

  uint64_t i = 0;
  for(auto abc: ABC) {
    if(i == K) break;
    std::cout << abc << std::endl;
    i++;
  }

  return 0;
}
