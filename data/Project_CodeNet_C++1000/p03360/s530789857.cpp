#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <math.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)

typedef long long ll;


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  int a,b,c,k;
  cin >> a >> b >> c >> k;

  int max_sum = 0;
  rep(i, k) {
      if (max({a,b,c}) == a) a *= 2;
      if (max({a,b,c}) == b) b *= 2;
      if (max({a,b,c}) == c) c *= 2;
  }
  max_sum += a + b + c;
  
  cout << max_sum << endl;
  return 0;
}