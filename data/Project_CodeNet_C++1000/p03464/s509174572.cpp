#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#include <string>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)
#pragma GCC optimize("unroll-loops")

#define DEBUG(x) cout << ">> " << #x << ": " << x << endl;
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;

int main() { _
  int k; cin >> k;
  vector<ll> v(k, 0);
  for (int i = 0; i < k; i++) {
    cin >> v[i];
  }
  ll minn = 2, maxx = 3;
  if (v[k-1] != 2) {
    cout << -1 << endl;
    return 0;
  }
  else {
    for (int i = k-2; i >= 0; i--) {
      if (v[i] > maxx) {
        cout << -1 << endl;
        return 0;
      }
      else maxx = (ll (maxx/v[i]) + 1) * v[i] - 1;

      if (maxx < 0) maxx = __LONG_LONG_MAX__;

      if (v[i] < minn) {
        minn = minn % v[i] == 0 ? minn : (ll (minn/v[i]) + 1) * v[i];
      }
      else minn = v[i];

      if (minn > maxx) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << minn << " " << maxx << endl;
  return 0;
}