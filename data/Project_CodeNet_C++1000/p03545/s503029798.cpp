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
  string abcd;
  cin >> abcd;
  int a, b, c, d;
  a = stoi(abcd.substr(0, 1));
  b = stoi(abcd.substr(1, 1));
  c = stoi(abcd.substr(2, 1));
  d = stoi(abcd.substr(3, 1));

  int op[2] = {1, -1};

  for (auto op1 : op) {
    for (auto op2 : op) {
      for (auto op3 : op) {
        if (a + op1 * b + op2 * c + op3 * d == 7) {
          cout << a << (op1 == 1 ? "+" : "-") << b << (op2 == 1 ? "+" : "-")
               << c << (op3 == 1 ? "+" : "-") << d << "=7" << endl;
          return 0;
        }
      }
    }
  }
}
