#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;

  if (a == b) {
    ans = c;
  } else if (b == c) {
    ans = a;
  } else if (c == a) {
    ans = b;
  }

  cout << ans << endl;
  
  return 0;
}