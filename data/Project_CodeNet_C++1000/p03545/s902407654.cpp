#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string tmp;
  cin >> tmp;
  long a, b, c, d;
  a = stol(to_string(tmp.at(0) - '0'));
  b = stol(to_string(tmp.at(1) - '0'));
  c = stol(to_string(tmp.at(2) - '0'));
  d = stol(to_string(tmp.at(3) - '0'));

  long n = 3;
  vector<char> op(n);

  for (long bit = 0; bit < (1 << n); bit++) {
    for (long iflag = 0; iflag < n; iflag++) {
      if (bit & (1 << iflag)) {
        op.at(iflag) = '+';
      } else {
        op.at(iflag) = '-';
      }
    }

    long val = a;
    if (op.at(0) == '+') {
      val += b;
    } else {
      val -= b;
    }
    if (op.at(1) == '+') {
      val += c;
    } else {
      val -= c;
    }
    if (op.at(2) == '+') {
      val += d;
    } else {
      val -= d;
    }
    if (val == 7) {
      cout << a << op.at(0) << b << op.at(1) << c << op.at(2) << d << "=7"
           << endl;
      return 0;
    }
  }
}
