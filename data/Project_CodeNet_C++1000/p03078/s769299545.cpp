#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  ll x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z), ab, abc;
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  rep(i, x)rep(j, y) ab.push_back(a[i]+b[j]);
  sort(ab.rbegin(), ab.rend());
  sort(c.rbegin(), c.rend());
  int n = min(k, x*y);
  rep(i, n)rep(j, z) abc.push_back(ab[i]+c[j]);
  sort(abc.rbegin(), abc.rend());
  rep(i, k) cout << abc[i] << endl;
  
  return 0;
}