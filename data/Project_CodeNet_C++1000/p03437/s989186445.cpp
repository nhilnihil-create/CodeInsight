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
  return abs(m*n)/gcd(m, n);
}

int main() {
  ll X, Y;
  cin >> X >> Y;
  if (lcm(X, Y)==X) cout << -1 << endl;
  else cout << X << endl;
}