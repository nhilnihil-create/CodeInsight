#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

constexpr char newl = '\n';
constexpr double eps = 1e-10;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << '\n';
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
template<class T> void Print(vector<T> v) {
  F0R(i, v.size()) {
    cout << v[i] << ' ';
  }
  cout << newl;
}

#if 1

class UnionFind {
public:
  UnionFind(int size) : size(size) {

    par = vector<int>(size, -1);
  }

  int GetRoot(int v) {
    int root = v;
    while (par[root] >= 0) {
      root = par[root];
    }
    if (root != v) {
      par[v] = root;
    }
    return root;
  }

  bool IsUnion(int a, int b) {
    int ra = GetRoot(a), rb = GetRoot(b);

    return ra == rb && ra >= 0;
  }

  int GetUnionSize(int a) {
    return -par[GetRoot(a)];
  }

  void Unite(int a, int b) {
    int ra = GetRoot(a), rb = GetRoot(b);

    if (ra == rb) return;

    if (GetUnionSize(ra) > GetUnionSize(rb)) {
      par[ra] += par[rb];
      par[rb] = ra;
    }
    else {
      par[rb] += par[ra];
      par[ra] = rb;
    }
  }

protected:

  // 親がいれば、親のindexを入れる
  // 親がいなければ、グループのサイズを負にして入れておく（一人なら-1）
  vector<int> par;

  int size;
};

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> as(M);
  F0R(i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    as[i] = { a,b };
  }
  UnionFind uf(N);
  vector<i64> rs(M);
  i64 r = (i64)N * (N - 1) / 2;
  RF0(i, M) {
    rs[i] = r;
    if (!uf.IsUnion(as[i].first, as[i].second)) {
      r -= (i64)uf.GetUnionSize(as[i].first) * uf.GetUnionSize(as[i].second);
      uf.Unite(as[i].first, as[i].second);
    }
  }
  F0R(i, M) {
    cout << rs[i] << newl;
  }
}
#endif
