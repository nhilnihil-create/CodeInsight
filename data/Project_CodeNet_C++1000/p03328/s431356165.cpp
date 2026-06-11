#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <math.h>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)

typedef long long ll;


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  ll a, b;
  cin >> a >> b;
  ll diff = b - a;

  ll ans = 0;
  rep(i, diff) 
  {
      ans += i;
  }
  ans -= b;
  cout << ans << endl;
  return 0;
}