#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <set>
#include <math.h>
#define pai 3.14159265358979323846264338327950288;
#define keta(n) cout << fixed << setprecision((n));
using ll = long long;
int main()
{
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int ans = 0;
  for (int a = 0; a <= A; a++) {
    for (int b = 0; b <= B; b++) {
      for (int c = 0; c <= C; c++) {

        int x = 500 * a + 100 * b + 50 * c;
        if (x == X) {
          ans++;
        }
      }

      /* code */
    }

    /* code */
  }
  cout << ans << endl;
}
