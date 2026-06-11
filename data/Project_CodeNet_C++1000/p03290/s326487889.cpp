#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int D, G; std::cin >> D >> G; G/=100;
  std::vector<int> p(D), c(D);
  for(int i = 0; i < D; ++i) {
    std::cin >> p[i] >> c[i];
    c[i] /= 100;
  }
  int ans = 1001;
  for(int s = 0; s < (1<<D); ++s) {
    int cur = 0, g = 0;
    for(int i = 0; i < D; ++i) if((1<<i)&s) {
      cur += p[i];
      g += c[i] + p[i]*(i+1);
    }
    if(g < G) for(int i = D-1; i >= 0; --i) if(((1<<i)&s)==0) {
      int ma = (p[i]-1)*(i+1);
      if(g+ma >= G) {
        cur += (G-g+i)/(i+1);
        g = G;
        break;
      }
      cur += p[i]-1;
      g += ma;
    }
    if(g >= G) ans = std::min(ans, cur);
  }
  fin(ans);
  return 0;
}
