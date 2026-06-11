#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Yen;
  cin >> N >> Yen;
  
  int a, b, c;
  int r = 0;
  for (int i = 0; i <= N; i++) {
    if (Yen == 10000*i) {
      if (N == i) {
      a=i, b=0, c=0;
      r++;
      goto SKIP;
      }
    }
    for (int j = 0; j <= N-i; j++) {
      if (j == N-i) {
        if (Yen == 10000*i + 5000*j) {
        a=i, b=j, c=0;
        r++;
        goto SKIP;
        }
        else {
        j = 0;
        break;
        }
      }
      for (int k = 0; k <= N-i-j; k++) {
        if (k == N-i-j) {
          if (Yen == 10000*i + 5000*j + 1000*k) {
          a=i, b=j, c=k;
          r++;
          goto SKIP;
          }
          else {
          k = 0;
          break;
          }
        }
      } 
    }
  }
  SKIP:
  if (r == 0) cout << -1 << " " << -1 << " " << -1 << endl;
  if (r == 1) cout << a << " " << b << " " << c << endl;
  return 0;
}
