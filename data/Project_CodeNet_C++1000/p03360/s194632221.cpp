#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  vector <ll> v(3);
  ll n;
  rep(i, 3) cin >> v.at(i);
  sort(v.begin(), v.end());
  cin >> n;
  rep(i, n) v.at(2) *= 2;
  ll res = 0;
  rep(i, 3) res += v.at(i);
  cout << res << endl;
}