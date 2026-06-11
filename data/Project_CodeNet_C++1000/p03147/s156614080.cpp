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
  vector<ll> h(N);
  ll min_v = INF;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
    min_v = min(min_v, h[i]);
  }
  for (int i = 0; i < N; i++) {
    h[i] -= min_v;
  }
  ll ans = min_v;
  for (int i = 0; i < N; i++) {
    if (h[i] == 0) continue;
    ll res = h[i];
    ans += res;
    ll r = i;
    while (r + 1 < N && h[r + 1] != 0) r++;
    ll l = i + 1;
    while (l <= r) {
      if (h[l] < res) {
        res = h[l];
        h[l] = 0;
      } else {
        h[l] -= res;
      }
      l++;
    }
  }
  cout << ans << endl;
  return 0;
}