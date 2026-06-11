#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a.push_back(x);
  sort(a.begin(), a.end());

  ll d = 1001001001;
  for(int i = 1; i <= n; i++) {
    ll tmp = a[i] - a[i - 1];
    d = min(d, tmp);
    ll r = tmp % d;
    while(r != 0) {
      tmp = d;
      d = r;
      r = tmp % d;
    }
  }
  cout << d << endl;
  return 0;
}