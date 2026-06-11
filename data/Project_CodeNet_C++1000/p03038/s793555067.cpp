#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;

  vector<pair<ll, ll>> vec2(m);
  for (auto &v : vec2)
    cin >> v.first >> v.second;
  sort(vec2.begin(), vec2.end(),
       [](auto &lhs, auto &rhs) { return lhs.second > rhs.second; });

  int cnt = 0;
  for (auto &v : vec2) {
    if (n <= cnt)
      break;
    for (int i = 0; i < v.first; ++i)
      vec.push_back(v.second);
    cnt += v.first;
  }

  sort(vec.begin(), vec.end(), greater<ll>());

  cout << accumulate(vec.begin(), vec.begin() + n, 0LL) << endl;
}