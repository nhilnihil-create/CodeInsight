#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  string s;
  cin >> s;

  vector<int> id;
  rep(i, s.size()) {
    if (s[i] != 'x') {
      id.push_back(i);
    }
  }

  if (id.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  queue<char> q1, q2;
  if (id.size() % 2 != 0) {
    int M = id.size() / 2;
    rrep(i, id[M]) { q1.push(s[i]); }
    for (int i = id[M] + 1; i < s.size(); i++) {
      q2.push(s[i]);
    }
  } else {
    int M = id.size() / 2;
    for (int i = id[M - 1]; i >= 0; i--) {
      q1.push(s[i]);
    }
    for (int i = id[M]; i < s.size(); i++) {
      q2.push(s[i]);
    }
  }
  q1.push('$');
  q2.push('$');

  int result = 0;
  while (!q1.empty() || !q2.empty()) {
    if (q1.front() == q2.front()) {
      q1.pop();
      q2.pop();
    } else if (q1.front() == 'x') {
      q1.pop();
      result++;
    } else if (q2.front() == 'x') {
      q2.pop();
      result++;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << result << endl;

  return 0;
}