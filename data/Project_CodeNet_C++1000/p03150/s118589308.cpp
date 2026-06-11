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

const string T = "keyence";
const uint64_t L = T.size();

int main()
{
  string S;
  cin >> S;

  uint64_t N = S.size();
  auto substr_eq = [&] (uint64_t n) {
    uint64_t j = 0, m = N - (L - n);

    for (uint64_t i = 0; i < n && j < L; ++i, ++j) {
      if (S[i] != T[j]) { return false; }
    }

    for (uint64_t i = m; i < N && j < L; ++i, ++j) {
      if (S[i] != T[j]) { return false; }
    }

    return true;
  };

  bool flag = false;
  N_TIMES(n, L + 1) {
    flag |= substr_eq(n);
  }
  cout << (flag ? "YES" : "NO") << endl;

  return 0;
}