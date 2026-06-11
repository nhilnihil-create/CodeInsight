#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t k, a, b, ans;
  cin >> k >> a >> b;
  if ((b-a <= 2) || (k <= a-1)) {
    ans += k+1;
  } else {
    ans = a;
    k -= a-1;
    ans += (b-a) * (k/2);
    if (k % 2 == 1) ans++;
  }
  
  cout << ans << endl;
}