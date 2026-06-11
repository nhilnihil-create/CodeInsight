#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (int i = 0; i < (o); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  ll n, k; 
  cin >> n >> k;

  vector<ll> h(n);
  rep(i, n) {
      cin >> h[i];
  }
  sort(h.begin(), h.end());
//   rep(i, n) {
//       cout << h[i] << endl;
//   }

  ll diff_with_k = 1e9 + 1;
  rep(i, n-k+1) {
    diff_with_k = min(diff_with_k,h[i+k-1] - h[i]);
  }
  cout << diff_with_k << endl;
  return 0;
}