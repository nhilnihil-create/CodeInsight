#include <iostream>
#include <cmath>

int main()
{
  int X;
  std::cin >> X;

  int ret = -1;
  for(int b=1; b<=std::sqrt(X); b++) {
    int t = b;
    for(int p=2; p<=10; p++) { // 2^10 = 1024
      t *= b;
      if(X < t) {
        continue;
      } else if(ret < t) {
        ret = t;
      }
    }
  }

  std::cout << ret << std::endl;

  return 0;
}
