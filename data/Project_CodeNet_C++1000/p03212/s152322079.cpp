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
ll N;

void build(ll cur_val, int state, ll &cnt) {
  if (N < cur_val) return;
  if (state == 0b111) cnt++;
  build(cur_val * 10 + 7, state | 0b001, cnt);
  build(cur_val * 10 + 5, state | 0b010, cnt);
  build(cur_val * 10 + 3, state | 0b100, cnt);
}

int main() {
  cin >> N;
  ll ans = 0;
  build(0, 0, ans);
  cout << ans << endl;
  return 0;
}