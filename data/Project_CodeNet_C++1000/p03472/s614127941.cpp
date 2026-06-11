#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 1000000007;
const long long INF = 1LL << 60;
typedef pair<ll, ll> P;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, h;
  cin >> n >> h;
  vector<ll> a(n);
  vector<ll> b(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  ll cnt = 0;
  for (ll j = 0; j < n; j++) {
    if (a[0] <= b[j]) {
      h -= b[j];
      cnt++;
      if (h <= 0) {
        cout << cnt << endl;
        return 0;
      }
    } else {
      break;
    }
  }
  while (1) {
    if (h <= 0) {
      cout << cnt << endl;
      return 0;
    }
    h -= a[0];
    cnt++;
  }
}