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
    if(n % i == 0 && n / i != i && n / i > i + 1) {
      ans += n / i - 1;
    }
  }

  cout << ans << endl;
  return 0;
}