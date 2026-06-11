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
  vector<pair<ll, pair<ll, ll>>> v;
  ll t, x, y;
  for (int i = 0; i < N; i++) {
    cin >> t >> x >> y;
    v.push_back({t, {x, y}});
  }
  pair<ll, ll> cur_pos = {0, 0};
  ll cur_t = 0;
  for (int i = 0; i < N; i++) {
    ll diff_t = v[i].first - cur_t;
    ll diff_p = abs(v[i].second.first - cur_pos.first) +
                abs(v[i].second.second - cur_pos.second);
    if (diff_p <= diff_t && diff_t % 2 == diff_p % 2) {
      cur_t = v[i].first;
      cur_pos = v[i].second;
      continue;
    }
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}