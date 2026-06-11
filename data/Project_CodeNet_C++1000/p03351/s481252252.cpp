#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (abs(b - a) <= d && abs(c - b) <= d) {
    cout << "Yes" << endl;
  } else if (abs(c - a) <= d) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}