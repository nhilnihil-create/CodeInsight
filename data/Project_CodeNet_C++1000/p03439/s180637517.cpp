#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  int64_t n;
  cin >> n;

  cout << 0 << endl;
  string s;
  cin >> s;

  if (s == "Vacant") {
    return 0;
  }

  int64_t f = (s == "Female" ? 0 : 1);
  int64_t b = 1, e = n;
  while (b < e) {
    auto mid = (b + e) / 2;
    cout << mid << endl;
    cin >> s;

    if (s == "Vacant") {
      return 0;
    }

    int64_t tmp = (s == "Female" ? 0 : 1);

    if ((f + mid) % 2 == tmp) {
      b = mid + 1;
    } else {
      e = mid;
    }
  }

  cout << b << endl;
}