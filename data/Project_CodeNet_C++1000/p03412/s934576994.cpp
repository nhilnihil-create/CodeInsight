#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

template<typename T>
void fin(T const& v){ std::cout << v << std::endl; exit(0); }
int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<int> a(N), b(N);
  for(auto& ai: a) std::cin >> ai;
  for(auto& bi: b) std::cin >> bi;

  int ans = 0;
  for(int k = 28; k >= 0; --k) {
    int m = 1<<k;
    // a, b in [0, 2m) , a+b in [0, 4m-1)
    std::sort(a.begin(), a.end());
    int sum = 0;
    for(auto bi: b) {
      // count [m, 2m) + [3m, 4m)
      int s1 = std::lower_bound(a.begin(), a.end(), m+m-bi)
             - std::lower_bound(a.begin(), a.end(), m-bi);
      int s2 = a.end() - std::lower_bound(a.begin(), a.end(), m*3-bi);
      sum ^= s1^s2;
    }
    if(sum%2) ans += m;
    for(auto& ai: a) ai &= m-1;
    for(auto& bi: b) bi &= m-1;
  }
  fin(ans);
  return 0;
}
