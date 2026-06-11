#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string s;
  cin >> s;
  ll a_cnt = 0, ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s.substr(i, 2) == "BC") {
      ans += a_cnt;
      i++;
    } else if (s[i] == 'A')
      a_cnt++;
    else
      a_cnt = 0;
  }
  cout << ans << endl;
  return 0;
}