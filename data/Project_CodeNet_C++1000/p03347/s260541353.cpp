#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

  ll n;
  cin >> n;
  ll a[200100];
  rep(i, n) cin >> a[i];

  rep(i, n) {
    if (a[i] > (ll)i) {
      cout << -1 << endl;
      return 0;
    }
  }
  

  ll ans = 0;
  int i = n - 1;
  while (i > 0) {
    ans += a[i];
    while (a[i] - a[i - 1] == 1) i--;
    i--;
    if (i >= 0 && a[i] < a[i + 1] - 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  
  cout << ans << endl;

  return 0;

}
