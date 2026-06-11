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

int main()
{
  uint64_t N;
  cin >> N;

  vector<vector<bool>> edge(N, vector<bool>(N, true));
  if ((N % 2) == 0) {
    N_TIMES(n, N) {
      edge[n][(N - 1) - n] = false;
    }
  } else {
    N_TIMES(n, N - 1) {
      edge[n][(N - 2) - n] = false;
    }
  }

  uint64_t count = 0;
  list<pair<uint64_t, uint64_t>> edges;
  N_TIMES(n, N) {
    N_TIMES(m, n) {
      if (edge[n][m]) {
        ++count;
        edges.emplace_back(m + 1, n + 1);
      }
    }
  }

  cout << count << endl;
  for (auto &e : edges) {
    cout << e.first << ' ' << e.second << endl;
  }

  return 0;
}