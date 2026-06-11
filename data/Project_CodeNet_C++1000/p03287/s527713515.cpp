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
bool prime(ll n) {
  if (n == 1) {
    return false;
  } else {
    for (ll i = 2; i <= (ll)pow(n, 0.5); i++) {
      if (n%i == 0) return false;
    }
  }
  return true;
}
ll RepeatSquaring(ll n, ll p, ll m) {
  if (p == 0) return 1;
  if (p%2 == 0) {
    ll t = RepeatSquaring(n, p/2, m);
    return (t*t)%m;
  }
  return (n*RepeatSquaring(n, p-1, m))%m;
}

int main() {
  ll n, m;
  cin >> n >> m;
  vector <ll> v(n+1, 0);
  ll sum = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    sum += a;
    v.at(i+1) = sum%m;
  }
  map <ll, ll> score;
  vector <ll> u;
  rep(i, n+1) {
    if (score.count(v.at(i))) {
      score.at(v.at(i))++;
    } else {
      score[v.at(i)] = 1;
      u.push_back(v.at(i));
    }
  }
  ll ans = 0;
  rep(i, u.size()) {
    ll tmp = score.at(u.at(i));
    ans += tmp * (tmp-1) / 2;
  }
  cout << ans << endl;
  return 0;
}