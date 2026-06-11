#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 1; i <= N; i += 2) {
    int c = 1;
    int h = i;
    for (int j = 2; j < sqrt(i); j++) {
      int k = 1;
      while (h % j == 0) {
        h /= j;
        k++;
      }
      c *= k;      
    }
    if (h != 1) {
      c *= 2;
    }
    if (c == 8) {
      ans++;
    }
  }
  cout << ans << endl;
}