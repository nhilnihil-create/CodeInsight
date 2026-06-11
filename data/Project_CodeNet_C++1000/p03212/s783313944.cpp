#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  int ky[] = {0, 3, 5, 7};
  int ans = 0;
  for (int a1 = 0; a1 < 4; a1 ++) {
    for (int a2 = (a1 == 0 ? 0 : 1); a2 < 4; a2 ++) {
      for (int a3 = (a2 == 0 ? 0 : 1); a3 < 4; a3 ++) {
        for (int a4 = (a3 == 0 ? 0 : 1); a4 < 4; a4 ++) {
          for (int a5 = (a4 == 0 ? 0 : 1); a5 < 4; a5 ++) {
            for (int a6 = (a5 == 0 ? 0 : 1); a6 < 4; a6 ++) {
              for (int a7 = (a6 == 0 ? 0 : 1); a7 < 4; a7 ++) {
                for (int a8 = (a7 == 0 ? 0 : 1); a8 < 4; a8 ++) {
                  for (int a9 = (a8 == 0 ? 0 : 1); a9 < 4; a9 ++) {
                    int ok = 0;
                    int kj = 0;
                    kj *= 10;
                    kj += ky[a1];
                    kj *= 10;
                    kj += ky[a2];
                    kj *= 10;
                    kj += ky[a3];
                    kj *= 10;
                    kj += ky[a4];
                    kj *= 10;
                    kj += ky[a5];
                    kj *= 10;
                    kj += ky[a6];
                    kj *= 10;
                    kj += ky[a7];
                    kj *= 10;
                    kj += ky[a8];
                    kj *= 10;
                    kj += ky[a9];
                    ok |= 1 << a1;
                    ok |= 1 << a2;
                    ok |= 1 << a3;
                    ok |= 1 << a4;
                    ok |= 1 << a5;
                    ok |= 1 << a6;
                    ok |= 1 << a7;
                    ok |= 1 << a8;
                    ok |= 1 << a9;
                    if (kj <= N && ok >= 14) ans ++;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}
