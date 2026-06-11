#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<pair<ll, ll>> b(m);
  // vector<ll> c(m);
  // priority_queue<ll, vector<ll>, greater<ll>> q;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    b[i] = pair<ll, ll>(y, x);
  }
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  ll j = 0;
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] < b[j].first) {
      a[i] = b[j].first;
      b[j].second--;
      if (b[j].second <= 0) {
        j++;
      }
    }
    sum += a[i];
  }
  cout << sum << endl;
}