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

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 1; i < n; i++)
  {
    int cnt = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
      bool left = false, right = false;
      for (int j = 0; j < i; j++)
      {
        if (s[j] == c)
          left = true;
      }
      for (int j = i; j < n; j++)
      {
        if (s[j] == c)
          right = true;
      }
      if (left && right)
        cnt++;
    }
    ans = max(ans, cnt);
  }
 

cout << ans << endl;
}
