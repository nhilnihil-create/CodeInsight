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
  int upper, downer;
  bool um = false, dm = false;
  cin >> s;
  upper = stoi(s.substr(0, 2));
  downer = stoi(s.substr(2, 2));

  if (1 <= upper && upper <= 12) um = true;
  if (1 <= downer && downer <= 12) dm = true;

  if (um && dm) {
    cout << "AMBIGUOUS" << endl;
  } else if (um) {
    cout << "MMYY" << endl;
  } else if (dm) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }
}
