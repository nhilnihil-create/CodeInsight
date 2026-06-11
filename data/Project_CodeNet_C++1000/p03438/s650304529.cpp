#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  int64_t n;
  cin >> n;

  vector<int64_t> a(n), b(n);
  for (auto i : irange(0L, n)) {
    cin >> a[i];
  }
  for (auto i : irange(0L, n)) {
    cin >> b[i];
  }

  int64_t ka = 0, kb = 0;
  for (auto i : irange(0L, n)) {
    if (a[i] < b[i]) {
      ka += (b[i] - a[i]) / 2;
      ka += (b[i] - a[i]) % 2;
      kb += (b[i] - a[i]) % 2;
    } else {
      kb += a[i] - b[i];
    }
  }

  cout << (ka >= kb ? "Yes" : "No") << endl;
}