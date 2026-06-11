#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  int H, W, N; std::cin >> H >> W >> N;
  int sr, sc; std::cin >> sr >> sc;
  std::string S, T; std::cin >> S >> T;
  int l = 0, r = 0, u = 0, d = 0;

  for (int i = 0; i < N; ++i) {
    // Takahashi
    switch (S[i]) {
      case 'L':
        ++l;
        break;
      case 'R':
        ++r;
        break;
      case 'U':
        ++u;
        break;
      case 'D':
        ++d;
        break;
      defalt:
        break;
    }

    if (sr - u < 1 || sr  + d > H || sc - l < 1 || sc + r > W) {
      std::cout << "NO" << std::endl;
      return 0;
    }

    // Aoki
    switch (T[i]) {
      case 'L':
        if(sc + r > 1) --r;
        break;
      case 'R':
        if(sc - l < W) --l;
        break;
      case 'U':
        if(sr + d > 1) --d;
        break;
      case 'D':
        if(sr - u < H) --u;
        break;
      default:
        break;
    }
  }

  std::cout << "YES" << std::endl;
}
