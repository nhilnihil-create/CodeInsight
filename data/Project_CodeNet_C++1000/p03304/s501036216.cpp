#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m, d;
  cin >> n >> m >> d;
  if(d == 0) cout << setprecision(20) << (double)(m-1) / n << endl;
  else cout << setprecision(20) << (double)(2*n-2*d) / (n * n) * (m - 1) << endl;
}
