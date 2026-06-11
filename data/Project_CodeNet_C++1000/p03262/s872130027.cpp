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

int gcd(int a, int b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

ll gcd_arr(vector<ll> &a) {
  ll n = a.size();
  for (ll i = n - 2; i >= 0; i--) {
    a[i] = gcd(a[i], a[i + 1]);
  }
  return a.front();
}

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N, X;
  scanf("%lld %lld", &N, &X);

  vector<ll> x_list;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);

    x_list.emplace_back(abs(v - X));
  }

  ll ans = gcd_arr(x_list);

  cout << ans << endl;
}
