#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

template<typename T>
void fin(T const& v){ std::cout << v << std::endl; exit(0); }
int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<int> tsum(N+1), vmax(N);

  // unit = 0.5
  tsum[0] = 0;
  for(int i = 0; i < N; ++i) {
    int t; std::cin >> t; tsum[i+1] = tsum[i] + t + t;
  }
  for(auto& vi: vmax) { std::cin >> vi; vi += vi; }

  std::vector<int> v(tsum[N]+1, 200);
  v[0] = 0;
  for(int i = 0; i < N; ++i) {
    int tb = tsum[i], te = tsum[i+1];
    for(int t = tb; t < te; ++t) {
      v[t+1] = std::min(v[t]+1, vmax[i]);
    }
  }
  v[tsum[N]] = 0;
  for(int i = N; i > 0; --i) {
    int tb = tsum[i], te = tsum[i-1];
    for(int t = tb; t > te; --t) {
      int nv = std::min(v[t]+1, vmax[i-1]);
      v[t-1] = std::min(v[t-1], nv);
    }
  }
  int ans = 0;
  for(int i = 0; i < tsum[N]; ++i) ans += v[i] + v[i+1];
  char const *points[] = { "", ".125", ".25", ".375", ".5", ".625", ".75", ".875" };
  std::cout << ans/8 << points[ans%8] << std::endl;
  return 0;
}
