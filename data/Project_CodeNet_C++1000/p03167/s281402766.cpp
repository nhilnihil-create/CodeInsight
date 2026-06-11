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
  int H, W;
  char tmp;
  cin >> H >> W;
  vector<vector<bool>> a(H, vector<bool>(W, false));
  vector<vector<ll>> c(H, vector<ll>(W, 0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> tmp;
      if (tmp == '.') {
        a[i][j] = true;
      } else {
        a[i][j] = false;
      }
    }
  }
  c[0][0] = 1;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i < H - 1 && a[i + 1][j])
        c[i + 1][j] = (c[i + 1][j] + c[i][j]) % 1000000007;
      if (j < W - 1 && a[i][j + 1])
        c[i][j + 1] = (c[i][j + 1] + c[i][j]) % 1000000007;
    }
  }
  cout << c[H - 1][W - 1] << endl;
}
