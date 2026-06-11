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

using namespace std;

namespace State { enum { Unknown = 0, Vacant = 1, Male, Female }; };

int query(uint64_t x)
{
  cout << x << endl;

  string y;
  cin >> y;

  if (y == "Vacant") { return State::Vacant; } else
  if (y == "Male")   { return State::Male;   } else
  if (y == "Female") { return State::Female; } else
  return State::Unknown;
}

uint64_t search(int S, int T, uint64_t L, uint64_t R)
{
  auto length_is_odd = [](uint64_t L, uint64_t R) {
    return ((R - L + 1) & 1) == 1;
  };

  uint64_t X = (L + R) >> 1;
  if (R - L <= 1) { return L; }

  int status = query(X);
  if (status == State::Vacant) {
    return X;
  }

  // [L, X]
  if (length_is_odd(L, X)) {
    if (S != status) {
      return search(S, status, L, X);
    }
  } else {
    if (S == status) {
      return search(S, status, L, X);
    }
  }

  // [X, R]
  if (length_is_odd(X, R)) {
    if (T != status) {
      return search(status, T, X, R);
    }
  } else {
    if (T == status) {
      return search(status, T, X, R);
    }
  }

  return static_cast<uint64_t>(-1);
}

uint64_t solve(uint64_t N)
{
  int status_L = query(0), status_R = query(N - 1);
  if (status_L == State::Vacant) { return 0; }
  if (status_R == State::Vacant) { return N - 1; }

  return search(status_L, status_R, 0, N - 1);
}

int main()
{
  uint64_t N;
  cin >> N;

  cout << solve(N) << endl;

  return 0;
}