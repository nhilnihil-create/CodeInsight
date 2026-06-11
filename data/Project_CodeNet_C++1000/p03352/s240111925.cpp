#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  
  int ans = 1;
  for (int i = 2; i < 32; i++) {
    for (int j = 2; j < 10; j++) {
      int a = pow(i,j);
      if (a <= x) {
        ans = max(ans, a);
      }
    }
  }
  cout << ans << endl;
}
