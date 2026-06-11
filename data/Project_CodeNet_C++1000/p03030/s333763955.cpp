#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using T = tuple<string, int, int>;

int n;

int main() {
  cin >> n;
  vector<T> v(n);
  rep (i, n) {
    cin >> get<0>(v[i]) >> get<1>(v[i]);
    get<2>(v[i]) = i+1;
  }
  sort(v.begin(), v.end(), [](auto const& a, auto const& b) {
    if (get<0>(a) == get<0>(b)) {
      return get<1>(a) > get<1>(b);
    } else {
      return get<0>(a) < get<0>(b);
    }
  });
  rep (i, n) {
    cout << get<2>(v[i]) << endl;
  }
  return 0;
}
