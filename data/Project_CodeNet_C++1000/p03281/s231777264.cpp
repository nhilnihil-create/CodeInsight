#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cctype>     // isupper, islower, isdigit, toupper, tolower
#include <cstdint>    // int64_t, int*_t
#include <cstdio>     // printf
#include <deque>      // deque
#include <iomanip>    // fixed, setprecision
#include <iostream>   // cout, endl, cin
#include <map>        // map
#include <numeric>    // accumulate
#include <queue>      // queue, priority_queue
#include <set>        // set
#include <stack>      // stack
#include <string>     // string, to_string, stoi
#include <tuple>      // tuple, make_tuple
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <utility>        // pair, make_pair
#include <vector>         // vector
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int N;
  cin >> N;
  vector<vector<bool>> d(N + 1, vector<bool>(N + 1, false));
  vector<int> cnt(N + 1, 0);
  for (int i = 1; i <= N; i += 2) {
    for (int j = 1; j <= sqrt(i); j++) {
      if (i % j == 0) {
        d[i][j] = true;
        d[i][i / j] = true;
      }
    }
    cnt[i] = count(d[i].begin(), d[i].end(), true);
  }

  cout << count(cnt.begin(), cnt.end(), 8) << endl;
}
