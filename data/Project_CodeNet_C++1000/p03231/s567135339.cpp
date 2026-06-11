#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

// 最大公約数
ll gcd(ll m, ll n) {
  if (n==0) return abs(m);
  else return gcd(n, m%n);
}

// 最小公倍数
ll lcm(ll m, ll n) {
  return abs(m)/gcd(m, n)*abs(n);
}

int main() {
  ll N, M;
  string S, T;
  cin >> N >> M >> S >> T;
  ll L = lcm(N, M);
  bool can = true;
  for (ll k=0; k<gcd(N, M); k++) {
    can = true;
    ll a = k*(N/gcd(N, M)), b = k*(M/gcd(N, M));
    if (S[a]!=T[b]) {
      can = false;
      break;
    }
  }
  if (can) cout << L << endl;
  else cout << -1 << endl;
}