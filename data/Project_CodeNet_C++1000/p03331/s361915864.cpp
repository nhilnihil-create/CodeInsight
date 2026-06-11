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
  ll ans = INF;
  ll b;
  string s_a, s_b;
  for (int a = 1; a < N; a++) {
    b = N - a;
    s_a = to_string(a);
    s_b = to_string(b);
    ll cnt = 0;
    for (auto c : s_a) {
      cnt += c - '0';
    }
    for (auto c : s_b) {
      cnt += c - '0';
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}