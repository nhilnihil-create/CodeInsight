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
const ll MOD = 1000000007;
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<ll> a(200, 1);
  for(int i = 0; i < n; i++) {
    a[s[i]]++;
  }
  ll ans = 1;
  for(int i = 0; i < 200; i++) {
    if(a[i] == 1) {
      continue;
    }
    ans *= a[i];
    ans %= MOD;
  }
  ans -= 1;
  if(ans < 0) {
    ans += MOD;
  }
  cout << ans << endl;
  return 0;
}