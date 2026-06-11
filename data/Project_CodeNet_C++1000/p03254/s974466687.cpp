#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  sort(a.begin(), a.end());
  int count = 0;

  for (int i = 0; i < n; i++) {
    x -= a.at(i);

    if (x < 0) {
      break;
    }
    count++;

    /* if (x >= 0) { */
    /*   count++; */
    /* } */
  }

  if (x > 0) {
    count--;
  }
  cout << count << endl;
}
