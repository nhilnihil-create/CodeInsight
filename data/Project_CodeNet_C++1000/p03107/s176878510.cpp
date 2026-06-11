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
  string s;
  cin >> s;
  int red, blue;
  red = count(s.begin(), s.end(), '0');
  blue = count(s.begin(), s.end(), '1');
  cout << min(red, blue) * 2 << endl;
}
