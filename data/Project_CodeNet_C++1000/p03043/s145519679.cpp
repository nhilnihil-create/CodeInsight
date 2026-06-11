#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int main() {
  int n, k;
  cin >> n >> k;
  double res = 0;
  rep2(i, n) {
    double tmp = (double)1 / n;
    int now = i;
    while (now < k) {
      now *= 2;
      tmp /= 2;
    }
    res += tmp;
  }
  cout << setprecision(15) << res << endl;
  return 0;
}