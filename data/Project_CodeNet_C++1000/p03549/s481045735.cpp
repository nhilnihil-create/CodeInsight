#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  ll n, m;
  cin >> n >> m;
  ll k = 1LL << m;
  ll t = 100 * (n - m) + 1900 * m;
  cout << t * k << endl;
  return 0;
}