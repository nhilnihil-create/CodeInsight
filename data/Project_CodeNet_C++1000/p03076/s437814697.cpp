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
typedef long long ll;
typedef unsigned long long ull;

int main() {
  vector<pair<int, int>> M(5);
  int t, m, c = 0;
  for (int i = 0; i < 5; i++) {
    cin >> t;
    m = t % 10;
    if (m == 0) m = 10;
    M[i] = make_pair(m, t);
  }
  sort(M.rbegin(), M.rend());
  for (int i = 0; i < 4; i++) {
    c += ceil(get<1>(M[i]) / 10.0) * 10;
  }
  c += get<1>(M[4]);
  cout << c << endl;
}
