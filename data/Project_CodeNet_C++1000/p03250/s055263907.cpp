#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int ans = max(10*a+b+c, a+10*b+c);
  ans = max(ans, a+b+10*c);

  cout << ans << endl;
}