#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct item {
  ll a, b;
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<item> vec(n);
  for (auto &v : vec) {
    cin >> v.a >> v.b;
  }

  sort(vec.begin(), vec.end(), [](auto &lhs, auto &rhs) { return lhs.a < rhs.a; });

  ll ans = 0;
  ll cnt = 0;
  for (auto &v : vec) {
    ll tmp = min(m, cnt + v.b);
    ans += (tmp - cnt) * v.a;
    cnt = tmp;
    if (cnt == m)
      break;
  }
  cout << ans << endl;
}