#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

constexpr unsigned Mod = 1000000007;

constexpr unsigned Add(unsigned a, unsigned b) { return (a + b) % Mod; }

int main() {
  int N;
  scanf("%d", &N);
  static char S[3000];
  scanf("%s", S);
  static unsigned F[3000][3000];
  for (auto i = 0; i < N; ++i)
    F[0][i] = 1;
  for (auto i = 1; i < N; ++i) {
    if (S[i - 1] == '<') {
      F[i][0] = F[i - 1][0];
      for (auto j = 1; j < N - i; ++j)
        F[i][j] = Add(F[i][j - 1], F[i - 1][j]);
    }
    else {
      F[i][N - i - 1] = F[i - 1][N - i];
      for (auto j = N - i - 2; j >= 0; --j)
        F[i][j] = Add(F[i][j + 1], F[i - 1][j + 1]);
    }
  }
  printf("%u\n", accumulate(F[N - 1], F[N - 1] + N, 0u, Add));
  return 0;
}
