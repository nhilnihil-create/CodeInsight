#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int ans = 0; 
  int memo = 0;
  for (int i = 0; i < 5; i++) {
    int dish;
    cin >> dish;
    int memo2 = ((dish - 1) / 10 + 1) * 10;
    ans += memo2;
    memo = max(memo, memo2 - dish);
  }
  cout << ans - memo << endl;
}
    