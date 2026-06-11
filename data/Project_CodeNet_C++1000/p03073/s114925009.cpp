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
  string s;
  cin >> s;
  int bw = 0, wb = 0;
  for (int i = 0; i < s.length(); i++) {
    if (i % 2 == 0) {
      if (s[i] == '0') bw++;
      if (s[i] == '1') wb++;
    } else {
      if (s[i] == '1') bw++;
      if (s[i] == '0') wb++;
    }
  }
  cout << min(bw, wb) << endl;
}
