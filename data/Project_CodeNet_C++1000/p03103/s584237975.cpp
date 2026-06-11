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
  ll N, M, a, b, price = 0, cnt = 0;
  cin >> N >> M;
  vector<pair<ll, ll>> shop(N);
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    shop[i] = make_pair(a, b);
  }
  sort(shop.begin(), shop.end());
  for (auto s : shop) {
    if (get<1>(s) >= M - cnt) {
      price += (M - cnt) * get<0>(s);
      cout << price << endl;
      return 0;
    } else {
      price += get<1>(s) * get<0>(s);
      cnt += get<1>(s);
    }
  }
}
