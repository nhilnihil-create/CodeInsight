#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> vec(m);
  for (auto &v : vec)
    cin >> v;
  sort(vec.begin(), vec.end());

  vector<ll> vec2(max(n,m));
  for (ll i = 1; i < m; ++i)
    vec2[i-1] = vec[i] - vec[i-1];
  sort(vec2.begin(), vec2.end(), greater<ll>());

  cout << accumulate(vec2.begin() + n - 1, vec2.end(), 0) << endl;
}