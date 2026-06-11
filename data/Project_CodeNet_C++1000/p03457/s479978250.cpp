#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cctype>     // isupper, islower, isdigit, toupper, tolower
#include <cstdint>    // int64_t, int*_t
#include <cstdio>     // printf
#include <deque>      // deque
#include <iomanip>    // fixed, setprecision
#include <iostream>   // cout, endl, cin
#include <map>        // map
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

int main() {
  int N;
  cin >> N;
  int tb = 0, xb = 0, yb = 0, tc, xc, yc, td, dd;
  for (int i = 0; i < N; i++) {
    cin >> tc >> xc >> yc;
    td = tc - tb;
    dd = abs(xc - xb) + abs(yc - yb);
    if (td >= dd && (td - dd) % 2 == 0) {
      xb = xc;
      yb = yc;
      tb = tc;
      continue;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
