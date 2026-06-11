#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int n, x, m, sum = 0, d = 100010;
  cin >> n >> x;
  rep(i,n)
  {
    cin >> m;
    sum += m;
    d = min(d, m);
  }
  cout << n + (x - sum) / d;
}
