#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  double T, X;
  cin >> T >> X;
  double ans = T / X;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
