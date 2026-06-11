#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, Y) for (int(X) = 0; (X) < (Y); ++(X))
#define rrep(X, Y) for (int(X) = (Y)-1; (X) >= 0; --(X))
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve(long long n, std::vector<long long> a) {
  sort(all(a));
  ll num = a[n - 1];

  ll minDiff = 1e10;
  ll r = a[0];
  rep(i, n - 1) {
    ll tmp = abs(a[i] - (num - a[i]));
    if (tmp < minDiff) {
      minDiff = tmp;
      r = a[i];
    }
  }

  print(num << " " << r);
}

int main() {
  long long n;
  scanf("%lld", &n);
  std::vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  solve(n, std::move(a));
  return 0;
}
