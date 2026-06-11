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
  deque<char> q;
  for (int i = 0; i < s.length(); i++) {
    q.push_back(s[i]);
  }
  ll cnt = 0;
  if (s.length() == 1) {
    cout << 0 << endl;
    return 0;
  }
  while (!q.empty()) {
    if (q.front() == q.back()) {
      q.pop_front();
      q.pop_back();
    } else if (q.front() == 'x') {
      cnt++;
      q.pop_front();
    } else if (q.back() == 'x') {
      cnt++;
      q.pop_back();
    } else {
      cout << -1 << endl;
      return 0;
    }
    if (q.size() == 1 || q.size() == 0) break;
  }
  cout << cnt << endl;
  return 0;
}