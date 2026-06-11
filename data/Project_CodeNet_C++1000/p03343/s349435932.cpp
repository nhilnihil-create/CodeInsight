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
#define chmin(X, Y) (X) = min(X, Y);
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
const ll INF = 9 * 1e18;
const ll MOD = 1e9 + 7;

void solve(long long N, long long K, long long Q, std::vector<long long> A) {
  ll ans = INF;

  rep(i, 0, N) {
    ll Y = A[i];

    multiset<ll> all;
    multiset<ll> sec;
    rep(j, 0, N) {
      if (A[j] >= Y) {
        sec.insert(A[j]);
      } else {
        if (sec.size() >= K) {
          int ssize = sec.size() - K + 1;
          auto iter = sec.begin();
          rep(k, 0, ssize) {
            all.insert(*iter);
            iter++;
          }
        }
        sec.clear();
      }
    }

    if (sec.size() >= K) {
      int ssize = sec.size() - K + 1;
      auto iter = sec.begin();
      rep(k, 0, ssize) {
        all.insert(*iter);
        iter++;
      }
    }

    if (all.size() >= Q) {
      auto iter = all.begin();
      rep(i, 0, Q - 1) { iter++; }
      ll X = *iter;
      chmin(ans, X - Y);
    }
  }
  print(ans);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  long long Q;
  scanf("%lld", &Q);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, K, Q, std::move(A));
  return 0;
}
