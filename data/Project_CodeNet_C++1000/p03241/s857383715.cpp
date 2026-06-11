#include <iostream>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;

  set<ll> st;
  for (ll i = 1; i <= sqrt(m); ++i) {
    if (m / i * i != m)
      continue;
    st.insert(i);
    st.insert(m/i);
  }

  ll ans = 1;
  for (auto &v : st)
    if (v * n <= m)
      ans = max(ans, v);

  cout << ans << endl;
}
