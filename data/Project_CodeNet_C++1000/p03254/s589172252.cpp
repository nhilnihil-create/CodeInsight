#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main() {
  int n, lim;
  std::cin >> n >> lim;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());
  int result = 0;
  for(int i = 0;i < n; i++) {
    if(v[i] <= lim) {
      lim -= v[i];
      result++;
    }
  }
  if(result < n || 0 == lim)
    std::cout << result;
  else
    std::cout << n - 1;
}
