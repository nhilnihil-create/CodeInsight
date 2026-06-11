#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;
  partial_sum(vec.begin(), vec.end(), vec.begin());

  ll ans = 0;
  map<ll, ll> mp;
  mp[0] = 1;
  for (auto &v : vec) {
    auto itr = mp.find(v);
    if (itr != mp.end()) {
      ans += itr->second;
      ++mp[v];
    } else {
      mp[v] = 1;
    }
  }
  cout << ans << endl;
}
