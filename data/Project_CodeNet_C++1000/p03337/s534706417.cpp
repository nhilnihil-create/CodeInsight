#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int a, b;
  cin >> a >> b;
  int ans = max({
    a+b,
    a-b,
    a*b
  });
  cout << ans << endl;
  return 0;
}