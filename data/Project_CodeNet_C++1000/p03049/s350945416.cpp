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
  ll N;
  cin >> N;
  vector<string> s(N);
  queue<string> a, b, ab;
  string ans = "";
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') {
      ab.push(s[i]);
    } else if (s[i][0] == 'B') {
      b.push(s[i]);
    } else if (s[i][s[i].size() - 1] == 'A') {
      a.push(s[i]);
    } else {
      ans += s[i];
    }
  }
  if (!a.empty()) ans += a.front(), a.pop();
  while (!ab.empty()) ans += ab.front(), ab.pop();
  while (!a.empty() || !b.empty()) {
    if (!b.empty()) ans += b.front(), b.pop();
    if (!a.empty()) ans += a.front(), a.pop();
  }
  ll cnt = 0;
  for (int i = 0; i + 1 < ans.size(); i++) {
    if (ans[i] == 'A' && ans[i + 1] == 'B') {
      cnt++;
      i++;
    }
  }
  cout << cnt << endl;
  return 0;
}