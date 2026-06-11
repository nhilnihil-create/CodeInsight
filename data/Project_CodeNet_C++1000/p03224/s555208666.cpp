#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 4000000000000000000LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);
  std::cerr << std::fixed << std::setprecision(6);

  int N, NN;

  std::cin >> N;

  NN = N * 2;

  for (int i = 1; i * i <= NN; i ++)
    if (NN % i == 0) {
      int j = NN / i;

      if (i + 1 == j) {
        int w = i, h = j;

        std::vector<std::vector<int>> a(h, std::vector<int>(w));

        for (int k = 0, s = 1; k < w; s += w - k - 1, k ++)
          for (int l = k; l < w; l ++)
            a[k][l] = a[l + 1][k] = s + l;

        std::cout << "Yes" << std::endl;

        std::cout << a.size() << std::endl;

        for (const auto& i : a) {
          std::cout << i.size() << ' ';
          for (const auto& j : i)
            std::cout << j << ' ';
          std::cout << std::endl;
        }
        
        return 0;
      }
    }

  std::cout << "No" << std::endl;
  
  return 0;
}
