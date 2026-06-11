#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

int main() {
  ll N;
  scanf("%lld", &N);

  vector<ll> list;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list.emplace_back(v);
  }

  vll l(N);
  vll r(N);

  ll c;

  c = list[0];
  for (ll i = 0; i < N; i++) {
    c = gcd(c, list[i]);
    l[i] = c;
  }

  c = list[N - 1];
  for (ll i = N - 1; i >= 0; i--) {
    c = gcd(c, list[i]);
    r[i] = c;
  }

  ll ans = 0;

  ans = max(ans, r[1]);
  ans = max(ans, l[N - 2]);

  for (ll i = 1; i < N - 1; i++) {
    ll tmp = gcd(l[i - 1], r[i + 1]);
    ans = max(ans, tmp);
  }

  cout << ans << endl;
}
