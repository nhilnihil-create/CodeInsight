#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

using ll = long long;

int main() {
  ll N,x;
  cin >> N >> x;
  vector<ll> a(N);
  for(auto &e: a) {
    cin >> e;
  }
  sort(begin(a),end(a));
  partial_sum(begin(a),end(a),begin(a));
  ll ans = upper_bound(begin(a),end(a),x) - begin(a);
  if (a.back() < x) --ans;
  cout << ans << endl;
  return 0;
}
