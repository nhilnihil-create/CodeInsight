#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x;
  cin >> x;
  
  for (int i = x; i > 0; i--) {
    for (int j = 2; j * j <= i; j++) {
      if (i % j != 0)
        continue;
      int temp = i, count = 0;
      while (temp % j == 0) {
        count ++;
        temp /= j;
      }
      if (temp == 1 && count >= 2) {
        cout << i << endl;
        return 0;
      }
    }
  }
  cout << 1 << endl;
}
