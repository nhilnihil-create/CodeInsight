#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
  fastIO;
  llint r, d, xi;
  cin >> r >> d >> xi;

  for(int i=0; i<10; ++i) {
    xi = r * xi - d;
    cout << xi << endl;
  }
}
