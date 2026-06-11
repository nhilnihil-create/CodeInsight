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
  ll n, m;
  cin >> n >> m;
  vector<ll> p(m);
  vector<ll> y(m);
  vector<tuple<ll, ll, ll>> s;
  for (ll i = 0; i < m; i++) {
    cin >> p[i] >> y[i];
    s.emplace_back(p[i], y[i], i);
  }
  sort(s.begin(), s.end());
  // for (ll i = 0; i < m; i++) {
  //   tuple<ll, ll, ll> t = s[i];
  //   cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
  // }
  map<ll, ll> mp;
  vector<pair<ll, string>> ans;
  for (auto x : s) {
    // cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
    string f = "000000";
    string b = "000000";
    ll city = get<0>(x);
    mp[city]++;
    for (ll i = 5; i >= 0; i--) {
      ll num = city % 10;
      f[i] = num + '0';
      city /= 10;
    }
    ll city_num = mp[get<0>(x)];
    for (ll i = 5; i >= 0; i--) {
      ll num = city_num % 10;
      b[i] = num + '0';
      city_num /= 10;
    }
    ans.push_back(pair<ll, string>(get<2>(x), f + b));
  }
  sort(ans.begin(), ans.end());
  for (auto x : ans) {
    cout << x.second << endl;
  }
}