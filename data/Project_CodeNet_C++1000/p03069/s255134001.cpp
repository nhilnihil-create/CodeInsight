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
  string s;
  cin >> s;
  ll wht_cnt = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == '.') wht_cnt++;
  }
  ll ans = wht_cnt;
  for (int i = 0; i < N; i++) {
    if (s[i] == '#') {
      wht_cnt++;
    } else {
      wht_cnt--;
    }
    ans = min(wht_cnt, ans);
  }
  cout << ans << endl;
  return 0;
}