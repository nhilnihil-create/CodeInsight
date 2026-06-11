#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  int64_t x, y;
  cin >> x >> y;

  if (x % y == 0) {
    cout << -1 << endl;
  } else {
    cout << x << endl;
  }
}