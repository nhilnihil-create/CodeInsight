// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation, std::lower_bound
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>
#include <cmath> // std::atan2
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)

int main() {
  ll N, M, Q;
  cin >> N >> M >> Q;
  vector<ll> L(M), R(M);
  rep (i, M) {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
  }
  vector<ll> p(Q), q(Q);
  rep (i, Q) {
    cin >> p[i] >> q[i];
    p[i]--;
    q[i]--;
  }

  vector<vector<ll>> LRbin(N);
  rep (i, N) LRbin[i].resize(N,0);
  rep (i, M) {
    LRbin[L[i]][R[i]]++;
  }
  vector<vector<ll>> pqbin(N);
  rep (i, N) pqbin[i].resize(N,0);
  ll icount = M;
  for (ll i=0; i<N; ++i) {
    if (i > 0) {
      for (ll k=i-1; k<N; ++k) {
        icount -= LRbin[i-1][k];
      }
    }
    ll jcount = icount;
    ll count = 0;
    for (ll j=N-1; i<=j; --j) {
      if (j < N-1) {
        for (ll k=i; k<=j+1; ++k) {
          jcount -= LRbin[k][j+1];
        }
      }
      pqbin[i][j] = jcount;
    }
  }
  rep (i, Q) {
    cout << pqbin[p[i]][q[i]] << endl;
  }
  return 0;
}
