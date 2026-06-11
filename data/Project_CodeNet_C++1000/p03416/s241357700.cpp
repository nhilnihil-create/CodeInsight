#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, i, ans;
  cin >> a >> b;
  i = a;
  ans = 0;
  
  while (i <= b) {
    if (i % 10 == (i/10000) % 10000 && (i/10) % 10 == (i/1000) % 10)
      ans += 1;
    i++;
  }
  
  cout << ans << endl;
}
