#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,c,ans=0;
  cin >> n;
  for (int j = 1; j <= n; j+=2) {
    for (int i = 1; i <= j; i++) {
      if (j % i == 0) {
        c ++;
      }
    }
    if (c == 8) {
      //cout << j << c << endl;
      ans ++;
    }
    c = 0;
  }
  cout << ans << endl;
} 