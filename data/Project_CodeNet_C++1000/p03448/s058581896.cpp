#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x;
  int ans = 0;
  cin >> a >> b >> c >> x;
  
  for(int i = a; i > -1; i--) {
    for(int s = b; s > -1; s--) {
      for(int j = c; j > -1; j--) {
        if(x == (500 * i) + (100 * s) + (50 * j)) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}