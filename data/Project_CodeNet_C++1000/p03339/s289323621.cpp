#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  int N; std::cin >> N;
  std::string s; std::cin >> s;
  std::vector<int> p(N);
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    p[i] = 'E' == s[i];
    sum += p[i];
  }
  
  int ans = sum - p[0];
  int r = sum - p[0];
  int l = 0;
  for (int i = 1; i < N; ++i) {
    r -= p[i];
    l += p[i-1];
    ans = std::min(r+(i-l), ans);
  }
  std::cout << ans << std::endl;
  
}
