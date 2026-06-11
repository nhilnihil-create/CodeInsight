#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int count = 0;
  while (true) {
    int minnum = min(a, min(b, c));
    a -= minnum;
    b -= minnum;
    c -= minnum;
    int maxnum = max(a, max(b, c));

    if (a == 0) {
      a = maxnum / 2 * 2;
    } else if (b == 0) {
      b = maxnum / 2 * 2;
    } else if (c == 0) {
      c = maxnum / 2 * 2;
    }
    count += maxnum / 2;

    if (a / 2 == 0 && b / 2 == 0 && c / 2 == 0) {
      break;
    }
  }

  int count1 = 0;
  if (a == 1) {
    count1++;
  }
  if (b == 1) {
    count1++;
  }
  if (c == 1) {
    count1++;
  }
  if (count1 == 0) {
    cout << count << endl;
  } else if (count1 == 1) {
    cout << count + 1 << endl;
  } else {
    cout << count + 2 << endl;
  }
}
