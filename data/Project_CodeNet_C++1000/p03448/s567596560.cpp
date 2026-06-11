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
  int A, B, C, X, ax, bx, cx, p = 0;
  cin >> A >> B >> C >> X;
  for (int a = 0; a <= A; a++) {
    ax = a * 500;
    for (int b = 0; b <= B; b++) {
      bx = ax + b * 100;
      for (int c = 0; c <= C; c++) {
        cx = bx + c * 50;
        if (cx == X) p++;
      }
    }
  }
  cout << p << endl;
}
