#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int f(int k) {
  int res = 0;
  while (k > 0) {
    res += k % 10;
    k /= 10;
  }
  return res;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int sum = 0;
  for (int k = 1; k <= n; ++k) if (f(k) >= a && f(k) <= b) sum += k;
  cout << sum << endl;
  return 0;
}