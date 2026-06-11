#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll sum_a = 0, sum_b = 0;
  rep(i, n) sum_a += a[i];
  rep(i, n) sum_b += b[i];
  ll o = sum_b - sum_a;

  ll r = 0;
  rep(i, n) {
    if (a[i] > b[i]) r += a[i] - b[i];
    else if ((b[i] - a[i]) % 2) ++r;
  }

  // printf("sum_a = %lld, sum_b = %lld\n", sum_a, sum_b);
  // printf("o = %lld, r = %lld\n", o, r);

  if (o >= r) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}