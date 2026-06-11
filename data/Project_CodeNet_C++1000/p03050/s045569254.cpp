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
  ll n;
  cin >> n;
  ll ans = 0;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0 && n / i != i) {
      ll num = n / i - 1;
      if(n / num == n % num) {
        ans += n / i - 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}