#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma region template

#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

namespace Math {

ll modpow(ll b, ll p, ll m) {
  ll r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      r = r * b % m;
  return r;
}

ll modinv(ll b, ll m) { return modpow(b, m - 2, m); }

template <class T> T gcd(T a, T b) { return abs(__gcd(a, b)); }
template <class T> T clamp(T n, T l, T r) { return n < l ? l : n > r ? r : n; }
template <class T> T lcm(T a, T b) { return abs(a / gcd(a, b) * b); }
template <class T> T sgn(T n) { return n == 0 ? 0 : n > 0 ? 1 : -1; }

struct Log2Table {
  vector<int> val;
  // Last value that we computed to.
  int pmax = 0;

  Log2Table() {
    val.resize(1);
    val[0] = -1;
  }

  int get(int n) {
    if (n >= val.size()) {
      eprintf("Error: request log2[%d] but is not computed yet\n", n);
      exit(1);
    }

    return val[n];
  }

  void require(int n) {
    if (n < pmax)
      return;
    val.resize(n + 1);

    for (int i = 0; i < 30; i++)
      for (int j = max(1 << i, pmax + 1); j < min(1 << (i + 1), n + 1); j++)
        val[j] = i;

    pmax = n;
  }
};

Log2Table log2t;

// Generic modular integer.
template <int MOD> struct GModint {
  ll val;

  GModint() : val(0) {}
  GModint(ll v) : val(((v % MOD) + MOD) % MOD) {}

  const GModint operator-() const { return GModint(-val); }
  const GModint operator+(const GModint &g) const { return GModint(val + g.val); }
  const GModint operator-(const GModint &g) const { return *this + (-g); }
  const GModint operator*(const GModint &g) const { return GModint(val * g.val); }
  const GModint operator/(const GModint &g) const { return *this * g.inv(); }
  template <class T> const GModint operator^(const T t) const { return GModint(modpow(val, t, MOD)); }
  const GModint inv() const { return GModint(modinv(val, MOD)); }
};

using Modint = GModint<1000000007>;

} // namespace Math

namespace DS {

// Building a 0-based sparse table for associative operations.
// i.e. A op (B op C) = (A op B) op C
template <class T, class Combiner> struct SparseTable {
  int n, nlog;
  vector<vector<T>> st;
  Combiner combiner;

  SparseTable(int n, T *t) : n(n) {
    Math::log2t.require(n);

    nlog = Math::log2t.get(n);

    st.resize(nlog + 1);
    for (int i = 0; i <= nlog; i++)
      st[i].resize(n);

    for (int j = 0; j < n; j++)
      st[0][j] = t[j];
    for (int i = 1; i <= nlog; i++)
      for (int j = 0; j + (1 << (i - 1)) < n; j++)
        st[i][j] = combiner(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }

  T query(int l, int r) {
    if (l > r) {
      eprintf("Error: sparse table query (L, R) = (%d, %d).\n", l, r);
      exit(1);
    }

    l = Math::clamp(l, 0, n - 1);
    r = Math::clamp(r, 0, n - 1);

    int len = Math::log2t.get(r - l + 1);
    T val = st[len][l];
    l += 1 << len;

    if (l <= r)
      val = combiner(val, query(l, r));

    return val;
  }
};

template <class T> struct SparseTableCombinerSample {
  const T operator()(const T &a, const T &b) { return a + b; }
};

} // namespace DS

namespace Graph {

const int NODE_NIL = -1;

template <typename LenType> struct Edge {
  int from, to;
  LenType len;

  Edge(int from, int to, LenType len) : from(from), to(to), len(len) {}
};

template <typename LenType> struct Graph {
  using edge = Edge<LenType>;

  vector<vector<edge>> G;
  int n;

  Graph() {}

  void resize(int new_size) {
    n = new_size;
    G.resize(n + 1);
  }

  void add_edge(int from, int to, LenType len = 1) { G[from].push_back(edge(from, to, len)); }
  void add_bidir_edge(int u, int v, LenType len = 1) { add_edge(u, v, len), add_edge(v, u, len); }
};

template <typename LenType> struct Tree : public Graph<LenType> {
  using edge = typename Graph<LenType>::edge;
  using Graph<LenType>::n;
  using Graph<LenType>::G;

  int root;
  vector<LenType> depth, parent;

  void init_dfs(int n, int p = NODE_NIL) {
    typename vector<edge>::iterator it_parent = G[n].end();

    for (typename vector<edge>::iterator it = G[n].begin(); it != G[n].end(); it++) {
      if (it->to == p) {
        it_parent = it;
      } else {
        depth[it->to] = depth[n] + it->len;
        init_dfs(it->to, n);
      }
    }

    if (it_parent != G[n].end()) {
      G[n].erase(it_parent);
    }
  }

  void init_tree(int new_root = 1, int root_depth = 0) {
    root = new_root;

    depth.resize(n + 1);
    parent.resize(n + 1);

    depth[root] = root_depth;

    init_dfs(root);
  }
};

using UnweightedTree = Tree<int>;

} // namespace Graph

template <int MOD> ostream &operator<<(ostream &out, const Math::GModint<MOD> m) {
  out << m.val;
  return out;
}

template <class T> ostream &operator<<(ostream &out, const vector<T> v) {
  out << "[";
  for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
    out << *it;
    if (next(it) != v.end())
      out << ", ";
  }
  out << "]";
  return out;
}

template <class T, class U> ostream &operator<<(ostream &out, const map<T, U> m) {
  out << "{";
  for (typename map<T, U>::const_iterator it = m.begin(); it != m.end(); it++) {
    out << it->first << " -> " << it->second;
    if (next(it) != m.end())
      out << ", ";
  }
  out << "}";
}

template <class T> ostream &operator<<(ostream &out, const set<T> s) {
  out << "(";
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    out << *it;
    if (next(it) != s.end())
      out << ", ";
  }
  out << ")";
}

template <class T, class U> ostream &operator<<(ostream &out, const pair<T, U> p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

#pragma endregion template

string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    ll cd = 0, cm = 0, cdm = 0, acc = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'D')
        cd++;
      else if (s[j] == 'M')
        cm++, cdm += cd;
      else if (s[j] == 'C')
        acc += cdm;

      if (j - k + 1 >= 0) {
        if (s[j - k + 1] == 'D')
          cdm -= cm, cd--;
        else if (s[j - k + 1] == 'M')
          cm--;
      }
    }
    cout << acc << endl;
  }
}