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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> b(n);
  for (ll i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<ll> ans;
  for (ll i = 0; i < n; i++) {
    for (ll j = n - 1 - ans.size(); j >= 0; j--) {
      if (b[j] == j + 1) {
        ans.push_back(b[j]);
        b.erase(b.begin() + j);
        break;
      }
    }
  }
  if (b.size() != 0) {
    cout << -1 << endl;
    return 0;
  }
  reverse(ans.begin(), ans.end());
  for (ll i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}