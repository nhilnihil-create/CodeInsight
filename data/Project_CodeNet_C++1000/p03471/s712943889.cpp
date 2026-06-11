#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <iomanip>       // fixed, setprecision
using namespace std;

int main()
{
  int64_t N, Y, mm, gg, sen;
  cin >> N >> Y;
  Y /= 1000;
  for (int man = 0; man <= N; man++)
  {
    mm = man * 10;
    for (int gosen = 0; gosen <= N - man; gosen++)
    {
      gg = gosen * 5;
      sen = N - man - gosen;
      if (mm + gg + sen == Y)
      {
        cout << man << " " << gosen << " " << sen << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}
