#include <bits/stdc++.h>

int main(void)
{
  int N;
  std::cin >> N;

  int64_t num;
  std::vector<int64_t> L;

  L.push_back(2L);
  L.push_back(1L);

  if (N == 1) {
  }
  else {
    for (int i = 2; i <= N; i++) {
      num = L.at(i-1) + L.at(i-2);
      L.push_back(num);
    }
  }
  
  std::cout << L.at(N) << std::endl;
}