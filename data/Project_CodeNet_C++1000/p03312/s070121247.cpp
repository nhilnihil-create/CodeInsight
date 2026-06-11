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

#define rep(X, S, E) for (int(X) = (S); (X) < (E); ++(X))
#define rrep(X, S, E) for (int(X) = (E)-1; (X) >= (S); --(X))
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
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
const ll INF = 1e16;
const ll MOD = 1e9 + 7;

vl search_(vl &A, vl &acc, ll s, ll e) {
  ll l = s;
  ll r = e;
  ll m = (l + r) / 2;

  vl pq(2);
  pq[0] = acc[m] - acc[s];
  pq[1] = acc[e] - acc[m];

  ll diffMin = abs(pq[0] - pq[1]);

  ll cnt = 0;

  while (l <= r) {
    cnt++;

    ll lSum = acc[m] - acc[s];
    ll rSum = acc[e] - acc[m];

    if (lSum < rSum) {
      l = ++m;
    } else {
      r = --m;
    }

    m = (l + r) / 2;

    ll pq0 = acc[m] - acc[s];
    ll pq1 = acc[e] - acc[m];
    if (abs(pq0 - pq1) < diffMin) {
      diffMin = abs(pq0 - pq1);
      pq[0] = pq0;
      pq[1] = pq1;
    }
  }

  return pq;
}

vl search(ll n, vl &A, vl &acc) {
  vl pqrs(4);

  vl pq = search_(A, acc, 0, n);
  vl rs = search_(A, acc, n, acc.size() - 1);

  pqrs[0] = pq[0];
  pqrs[1] = pq[1];
  pqrs[2] = rs[0];
  pqrs[3] = rs[1];

  return pqrs;
}

ll calc(vl pqrs) {
  ll maxN = max(max(pqrs[0], pqrs[1]), max(pqrs[2], pqrs[3]));
  ll minN = min(min(pqrs[0], pqrs[1]), min(pqrs[2], pqrs[3]));
  return maxN - minN;
}

void solve(long long N, std::vector<long long> A) {
  vl acc(N + 1);
  rep(n, 1, N + 1) { acc[n] = acc[n - 1] + A[n - 1]; }

  ll ans = INF;
  rep(n, 2, N - 1) {
    vl pqrs = search(n, A, acc);
    ans = min(ans, calc(pqrs));
  }
  print(ans);
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
