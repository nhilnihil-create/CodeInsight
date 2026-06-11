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
  int n;
  cin >> n;
  bool judge = false;
  for (int c = 0; c < 25; c++) {
    for (int d = 0; d < 25; d++) {
      if (n == 4 * c + 7 * d) {
        judge = true;
      }
    }
  }
  if (judge == true)
    cout << "Yes" << endl;
  else if (judge == false)
    cout << "No" << endl;
}
