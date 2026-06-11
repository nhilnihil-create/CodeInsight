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
  set<char> atgc = {'A', 'T', 'G', 'C'};
  ll ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (atgc.count(s[i])) {
      int start = i;
      int end = i;
      while (end + 1 < s.size() && atgc.count(s[end + 1])) {
        end++;
      }
      ans = max(ans, (ll)(end - start + 1));
      i = end;
    }
  }
  cout << ans << endl;
  return 0;
}