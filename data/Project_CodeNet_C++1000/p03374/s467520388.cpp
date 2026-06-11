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
typedef vector<bool> vb;
typedef priority_queue<ll, vl> decendingQueue;              //降順
typedef priority_queue<ll, vl, greater<ll>> ascendingQueue; //昇順
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll INF = 9 * 1e18;
const ll MOD = 1e9 + 7;

ll calc(long long N, long long C, std::vector<long long> &x,
        std::vector<long long> &v) {
  vl leftAccVMinusX(N + 1);
  leftAccVMinusX[1] = v[0] - x[0];
  rep(i, 2, N + 1) {
    leftAccVMinusX[i] = leftAccVMinusX[i - 1] + v[i - 1] - x[i - 1] + x[i - 2];
  }

  vl rightAccVMinusX(N + 1);
  rightAccVMinusX[1] = v[N - 1] - 2 * (C - x[N - 1]);
  rep(i, 2, N + 1) {
    rightAccVMinusX[i] = rightAccVMinusX[i - 1] + v[N - i] -
                         2 * (C - x[N - i]) + 2 * (C - x[N + 1 - i]);
  }

  vl maxAccVMinusX(N + 1);
  rep(i, 1, N + 1) {
    maxAccVMinusX[i] = max(maxAccVMinusX[i - 1], leftAccVMinusX[i]);
  }

  ll ret = 0;
  rep(i, 0, N + 1) {
    ll tmp = rightAccVMinusX[i] + maxAccVMinusX[N - i];
    ret = max(ret, tmp);
  }
  return ret;
}

void solve(long long N, long long C, std::vector<long long> x,
           std::vector<long long> v) {
  ll rightFirst = calc(N, C, x, v);

  reverse(all(v));
  vl xrev(N);
  rep(i, 0, N) { xrev[i] = C - x[N - i - 1]; }
  ll leftFirst = calc(N, C, xrev, v);

  print(max(rightFirst, leftFirst));
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long C;
  scanf("%lld", &C);
  std::vector<long long> x(N);
  std::vector<long long> v(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &x[i]);
    scanf("%lld", &v[i]);
  }
  solve(N, C, std::move(x), std::move(v));
  return 0;
}
