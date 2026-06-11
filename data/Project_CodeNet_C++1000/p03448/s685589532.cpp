#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  
  int sa, sb, sc;
  int count = 0;
  for (int i = 0; i <= a; i++) {
    sa = 500 * i;
    if (sa == x) {
      count++;
      break;
    }
    for (int j = 0; j <= b; j++) {
      sb = sa + 100 * j; 
      if (sb == x) {
        count++;
        j = 0;
        break;
      }
      else if (j == b && sb + 50*c < x) {
        j = 0;
        break;
      }
      for (int k = 0; k <= c; k++) {
        sc = sb + 50 * k;
        if (sc == x) {
          count++;
          k = 0;
          break;
        }
        else if (k == c) {
          k = 0;
          break;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}