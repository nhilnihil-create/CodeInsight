#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;
  sort(vec.begin(), vec.end());

  int cnt = 0;
  for (ll i = 0; i < n; ++i) {
    if (i != 0)
      vec[i] += vec[i-1];
    if (vec[i] == x || (vec[i] < x && i != n - 1))
      cnt += 1;
  }

  cout << cnt << endl;
}
