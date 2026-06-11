#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = min ({
    abs(a-b)+abs(b-c),
    abs(a-c)+abs(c-b),
    abs(b-a)+abs(a-c),
    abs(b-c)+abs(c-a),
    abs(c-a)+abs(a-b),
    abs(c-b)+abs(b-a)});
  cout << ans << endl;
  return 0;
}