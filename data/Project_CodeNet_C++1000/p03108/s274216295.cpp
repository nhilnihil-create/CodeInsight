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

/*
template <typename T = long long>
class UnionFind {
  std::vector<T> data;

public:
  UnionFind(T size) {
    data.resize(size);
    std::iota(data.begin(), data.end(), 0);
  }

  bool unite(T x, T y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(
*/


struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M), B(M);
  rep (i, M) cin >> A[i] >> B[i];

  UnionFind clusters(N);

  vector<ll> ans(M+1);
  for (ll i = M; i > 0; --i) {
    if (i == M) {
      ans[i] = N * (N-1) / 2;
      continue;
    }
    else {
      ans[i] = ans[i+1];
    }
    ll convenience = clusters.size(A[i]-1) * clusters.size(B[i]-1);
    if (clusters.unite(A[i]-1, B[i]-1)) ans[i] -= convenience;
  }
  for (ll i = 1; i <= M; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}

