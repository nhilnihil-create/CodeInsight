#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}
ll factorial(ll n) {
  if (n == 1) {
    return 1;
  }
  ll ans = factorial(n-1);
  return ans*n;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
  return (a/gcd(a, b))*b;
}
bool is_prime(ll n) {
  for (ll i = 2; i*i <= n; i++) {
    if (n%i == 0) return false;
  }
  return n != 1;
}
ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll res = mod_pow(x*x%mod, n/2, mod);
  if (n & 1) res = res * x % mod;
  return res;
}

int main() {
  ll n;
  cin >> n;
  vector <vector <ll>> v(n, vector <ll> (3));
  rep(i, n) {
    ll x, y, h;
    cin >> x >> y >> h;
    v.at(i).at(0) = h, v.at(i).at(1) = x, v.at(i).at(2) = y;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  rep(i, 101) {
    rep(j, 101) {
      ll tmp = v.at(0).at(0) + abs(i-v.at(0).at(1)) + abs(j-v.at(0).at(2));
      bool flag = 1;
      rep(k, n) {
        if (v.at(k).at(0) != max(tmp-abs(i-v.at(k).at(1))-abs(j-v.at(k).at(2)), (ll)0)) {
          flag= 0;
        }
      }
      if (flag) {
        cout << i << ' ' << j << ' ' << tmp << endl;
        break;
      }
    }
  }
}