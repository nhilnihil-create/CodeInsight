#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <math.h>
using namespace std;

#define rep(i, o) for (int i = 0; i < (o); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)

typedef long long ll;


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  for (int i = a; i <= b; i++)
  {
      /* code */
      if (i >= a + k && i < b - k + 1) continue;
      cout << i << endl;
  }

  return 0;
}