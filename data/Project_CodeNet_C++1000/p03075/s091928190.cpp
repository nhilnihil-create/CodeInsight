#include <iostream>
#include <vector>

int main()
{
  constexpr int N = 5;

  std::vector<int> p(N);
  for(int i=0; i<N; i++) {
    std::cin >> p[i];
  }
  int k;
  std::cin >> k;

  int n_non_direct = 0;
  for(int i=0; i<N; i++) {
    for(int j=i+1; j<N; j++) {
      if(k < p[j] - p[i]) {
        n_non_direct++;
      }
    }
  }

  std::cout << (n_non_direct == 0 ? "Yay!" : ":(") << std::endl;
  return 0;
}
