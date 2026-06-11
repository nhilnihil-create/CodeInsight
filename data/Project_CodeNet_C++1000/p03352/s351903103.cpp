#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x;
  cin >> x;
  int ans = 1;
  for (int b = 2; b * b <= x; ++b) {
    int p = 2;
    while (pow(b, p) <= x) {
      ans = max(ans, (int)pow(b, p));
      ++p;
    }
  }
  cout << ans << endl;
  return 0;
}