#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  int n;
  cin >> n;
  ll l[87];
  l[0] = 2LL, l[1] = 1LL;
  f1(i, 2, n) l[i] = l[i - 2] + l[i - 1];
  cout << l[n] << endl;
  return 0;
}