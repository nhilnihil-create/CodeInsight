#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  int A[3], B[3];
  int C[3][3];
  rep(i, 3) {
    rep(j, 3) {
      cin >> C[i][j];
    }
  }

  rep(a1, 101) {
    rep(a2, 101) {
      rep(a3, 101) {
        int b1 = C[0][0] - a1;
        int b2 = C[0][1] - a1;
        int b3 = C[0][2] - a1;

        A[0] = a1;
        A[1] = a2;
        A[2] = a3;
        B[0] = b1;
        B[1] = b2;
        B[2] = b3;

        int ok = 1;
        rep(i, 3) {
          rep(j, 3) {
            if (A[i] + B[j] != C[i][j]) ok = 0;
          }
        }
        if(ok) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout <<"No" << endl;
  return 0;
}