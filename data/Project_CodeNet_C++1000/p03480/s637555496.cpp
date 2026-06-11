#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <complex>

#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;


ll powMod(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll t = powMod(x, n/2, mod);
  t = t * t % mod;
  if (n & 1) return t * x % mod;
  return t;
}

ll gcd(ll a, ll b) {
  if (a == 0 || b == 0) return a + b;
  if (b > a) return gcd(b, a);
  return gcd(b, a % b);
}

int main(void) {

  string s;
  cin >> s;
  int n = s.size();

  int k;
  if (n % 2 == 1) k = (n + 1)/2 - 1;
  else k = (n + 1)/2;

  k++;

  //s[n-k]からs[k-1]
  int b = 0, w = 0;
  for (int i = n - k; i < k; i++) {
    if (s[i] == '0') w++;
    else b++;
  }

  while (w * b == 0 && k < n) {
    k++;
    if (s[n-k] == '0') w++;
    else b++;
    if (s[k-1] == '0') w++;
    else b++;
  }

  if (w*b == 0) cout << k << endl;
  else cout << k - 1 << endl;

  return 0;

}
   
