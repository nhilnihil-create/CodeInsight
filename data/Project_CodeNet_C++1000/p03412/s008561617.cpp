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
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end());
    int sum = 0;
    int jm = 0, j2m = 0;
    for(int i = 0; i < N; ++i) {
      while(jm < N && a[i]+b[jm] < m) ++jm;
      while(j2m < N && a[i]+b[j2m] < m+m) ++j2m;
      sum ^= j2m - jm;
    }
    // count [3m, )
    int j3m = 0;
    for(int i = 0; i < N; ++i) {
      while(j3m < N && a[i]+b[j3m] < m*3) ++j3m;
      sum ^= N - j3m;
    }
    if(sum%2) ans += m;
    for(auto& ai: a) ai &= m-1;
    for(auto& bi: b) bi &= m-1;
  }
  fin(ans);
  return 0;
}
