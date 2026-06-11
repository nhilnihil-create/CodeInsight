#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

int main()
{
  const int n = 100000;
  std::vector<bool> is_prime;
  is_prime.resize(n, true);
  is_prime[1] = false;
  is_prime[2] = true;

  // find out prime
  for(int i=2; i<n; i++) {
    if(is_prime[i] == false) continue;

    for(int j=i+1; j<n; j++) {
      if(j % i == 0) {
        is_prime[j] = false;
      }
    }
  }
  // std::cout << "primes: ";
  // for(int i=2; i<n; i++) {
  //   if(is_prime[i]) {
  //     std::cout << i << ",";
  //   }
  // }
  // std::cout << std::endl;

  std::set<int> primes_like_2017;
  for(int i=3; i<n; i++) {
    if(is_prime[i] == false) continue;

    if(is_prime[(i+1)/2]) {
      primes_like_2017.insert(i);
    }
  }
  // std::cout << "2017 like: ";
  // std::for_each(primes_like_2017.begin(),
  //               primes_like_2017.end(),
  //               [](int x) { std::cout << x << ", "; });
  // std::cout << std::endl;

  int Q;
  std::cin >> Q;
  std::vector<int> l(Q), r(Q);
  for(int i=0; i<Q; i++) {
    std::cin >> l[i] >> r[i];
  }

  for(int i=0; i<Q; i++) {
    int ll = l[i], rr = r[i];
    int c = std::count_if(
        primes_like_2017.begin(),
        primes_like_2017.end(),
        [ll, rr](int x) -> bool
        {
          return ll <= x  && x <= rr;
        });
    std::cout << c << std::endl;
  }


  return 0;
}
