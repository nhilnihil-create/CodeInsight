#include <iostream>
#include <vector>

int main() {
  int N; std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) std::cin >> a[i];
  
  long long res = 0;
  int right = 0;
  long long sum = 0;
  
  for (int left = 0; left < N; ++left) {
    while (right < N && ((sum ^ a[right]) == sum + a[right])) {
      sum += a[right];
      ++right;
    }
    
    if (left == right) ++right;
    else sum -= a[left];
    
    res += (right - left);
    }
  
  std::cout << res << std::endl;
  
  return 0;
}
