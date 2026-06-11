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

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long M, std::vector<long long> L,
           std::vector<long long> R, std::vector<long long> D) {
  map<ll, map<ll, ll>> edges; // <from, <to, dist>>
  rep(m, M) {
    edges[L[m]][R[m]] = D[m];
    edges[R[m]][L[m]] = -D[m];
  }

  const ll INF = 1e12;
  vector<ll> dists(N + 1);
  dists.assign(N + 1, INF);
  for (ll i = 1; i <= N; i++) {
    if (dists[i] != INF) {
      continue;
    }

    queue<ll> que;
    que.push(i);
    dists[i] = 0;
    while (!que.empty()) {
      ll from = que.front();
      que.pop();

      map<ll, ll> toDists = edges[from];
      for (auto iter = toDists.begin(); iter != toDists.end(); iter++) {
        ll to = iter->fi;
        ll dist = iter->sc;

        if (dists[to] == INF) {
          dists[to] = dists[from] + dist;
          que.push(to);
        } else if (dists[to] != dists[from] + dist) {
          print(NO);
          return;
        }
      }
    }
  }

  print(YES);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> L(M);
  std::vector<long long> R(M);
  std::vector<long long> D(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &L[i]);
    scanf("%lld", &R[i]);
    scanf("%lld", &D[i]);
  }
  solve(N, M, std::move(L), std::move(R), std::move(D));
  return 0;
}
