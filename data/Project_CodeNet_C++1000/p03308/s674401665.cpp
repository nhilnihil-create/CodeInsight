#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
    std::cin >> N;
  std::vector<int> vec(N);

  for (size_t i = 0; i < N; i++) {
    std::cin >> vec.at(i);/* code */
  }
  sort(vec.begin(),vec.end());
  std::cout << vec.at(N-1)-vec.at(0) << '\n';
  return 0;
}
