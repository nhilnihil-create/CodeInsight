//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


int main() {
  ll k, a, b;
  cin >> k >> a >> b;
  if (k <= a) {
    cout << k + 1 << endl;
    return 0;
  }
  ll n = k - a - 1;
  ll m = n/2;
  ll num = (m+1)*b-m*a;
  if (n%2 == 1) num++;
  if (a > b) num = 0;
  cout << max(num, k+1) << endl;
  return 0;
}