#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for(int i = 1, i##_len = (n); i < i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define PRINT(A) std::cout << (#A) << ":" << (A) << std::endl;
using namespace std;
#define repi(itr, ds) for(auto itr = ds.begin(); itr != ds.end(); itr++)

// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for(T &x : vec) is >> x;
  return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "{";
  for(int i = 0; i < vec.size(); i++) {
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  }
  os << "}\n   ";
  return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
  os << "{";
  repi(itr, map_var) {
    os << *itr;
    itr++;
    if(itr != map_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
  os << "{";
  repi(itr, set_var) {
    os << *itr;
    itr++;
    if(itr != set_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}

#define DUMPOUT cerr

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
  DUMPOUT << head;
  if(sizeof...(Tail) > 0) {
    DUMPOUT << ", ";
  }
  dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                             \
  DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                             \
          << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl \
          << "    ",                                                          \
      dump_func(__VA_ARGS__)
#else
#define DEB if(false)
#define dump(...)
#endif

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9;

template <class Abel>
struct WeightedUnionFind {
  vector<int> par;
  vector<int> rank;
  vector<Abel> diff_weight;

  WeightedUnionFind(int n = 1, Abel SUM_UNITY = 0) { init(n, SUM_UNITY); }

  void init(int n = 1, Abel SUM_UNITY = 0) {
    par.resize(n);
    rank.resize(n);
    diff_weight.resize(n);
    for(int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
  }

  int root(int x) {
    if(par[x] == x) {
      return x;
    } else {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }

  Abel weight(int x) {
    root(x);
    return diff_weight[x];
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y, Abel w) {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(rank[x] < rank[y]) swap(x, y), w = -w;
    if(rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }

  Abel diff(int x, int y) { return weight(y) - weight(x); }
};

int main() {
  int N, M;
  cin >> N >> M;
  auto uf = WeightedUnionFind<int>(N);
  REP(i, M) {
    int L, R, D;
    cin >> L >> R >> D;
    if(uf.issame(L, R) && uf.diff(L, R) != D) {
      cout << "No" << endl;
      return 0;
    }
    uf.merge(L, R, D);
  }
  cout << "Yes" << endl;
}
