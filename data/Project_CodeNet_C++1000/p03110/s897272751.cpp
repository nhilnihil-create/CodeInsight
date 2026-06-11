#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long ll;
int main() {
  int n;
  string x;
  double u, b = 0, ub = 0;
  cin >> n;
  rep(i,n)
  {
    cin >> u >> x;
    if (x[0] == 'J') {
      b += u;
    } else {
      ub += u;
    }
  }
  ub *= 380000;
  ub += b;
  printf("%.6lf\n", ub);
  return 0;
}