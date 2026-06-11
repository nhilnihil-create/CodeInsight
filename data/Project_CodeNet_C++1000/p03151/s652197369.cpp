#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

template<typename T> using maximum_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
template<typename T> using minimum_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

using namespace std;

int main()
{
  uint64_t N;
  cin >> N;

  vector<uint64_t> A(N), B(N);
  N_TIMES(n, N) { cin >> A[n]; }
  N_TIMES(n, N) { cin >> B[n]; }

  uint64_t S = accumulate(A.begin(), A.end(), static_cast<uint64_t>(0));
  uint64_t T = accumulate(B.begin(), B.end(), static_cast<uint64_t>(0));
  if (S < T) {
    cout << -1 << endl;
    return 0;
  }

  maximum_heap<uint64_t> xs;
  minimum_heap<uint64_t> ys;
  N_TIMES(n, N) {
    if (A[n] >= B[n]) {
      xs.push(A[n] - B[n]);
    } else {
      ys.push(B[n] - A[n]);
    }
  }

  uint64_t r = 0;
  while (!xs.empty()) {
    uint64_t x = xs.top(); xs.pop();
    r += x;

    uint64_t c = 0;
    while (!ys.empty()) {
      uint64_t y = ys.top(); ys.pop();

      if (r < y) {
        ys.push(y);
        break;
      }

      r -= y;
      ++c;
    }

    if (ys.empty()) {
      if (c == 0) { xs.push(x); }
      break;
    }
  }

  cout << (N - xs.size()) << endl;

  return 0;
}