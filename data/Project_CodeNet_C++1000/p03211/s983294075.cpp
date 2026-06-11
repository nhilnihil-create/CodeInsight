#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  string str;
  cin >> str;

  ll ans = INF;

  for (ll i = 0; i < str.length() - 2; i++) {
    string s = str.substr(i, 3);
    ll v = stoll(s);
    v = abs(753 - v);

    ans = min(ans, v);
  }

  cout << ans << endl;
}
