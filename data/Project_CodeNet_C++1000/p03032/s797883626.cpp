#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main()
{
  int N, K;
  std::cin >> N >> K;
  std::vector<int> D(N);
  for(int i=0; i<N; i++) {
    std::cin >> D[i];
  }

  int ret = 0;

  // number of dequeue
  for(int k=0; k<=K; k++) {
    // number of right
    for(int r=0; r<=k; r++) {
      // std::cout << "k: " << k
      //           << " r: " << r
      //           << " k-r:" << k-r
      //           << std::endl;
      int tmp = 0;
      std::multiset<int> neg;
      // get from right
      for(int i=0; i<std::min(r, N); i++) {
        int d = D[N - 1 - i];
        if(d >= 0) {
          // std::cout << "d " << d << std::endl;
          tmp += d;
        } else {
          neg.insert(d);
        }
      }
      // get from left
      for(int i=0; i<std::min(k-r, N - std::min(r, N)); i++) {
        int d = D[i];
        if(d >= 0) {
          // std::cout << "d " << d << std::endl;
          tmp += d;
        } else {
          neg.insert(d);
        }
      }
      // remove neg
      int n_remove = K - k;
      auto it = neg.begin();
      for(int i=0; i<(int)neg.size(); i++, it++) {
        // std::cout << "neg" << i << ": " << *it << std::endl;
        if(n_remove <= i) {
          // std::cout << "boo" << std::endl;
          tmp += *it;
        }
      }
      if(ret < tmp) {
        ret = tmp;
      }
    }
  }


  std::cout << ret << std::endl;

  return 0;
}
