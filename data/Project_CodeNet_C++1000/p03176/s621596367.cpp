/*
 *    author:  Gary Shih
 *    created: 2020-05-05 16:52:14
 */
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

// Debug {{{
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// }}}

class SegmentTree {
 public:
  static const int N = 2e5;

  int index = 2;
  vector<long long> val;
  vector<int> lNode, rNode;

  SegmentTree() {
    val.resize(20 * N);
    lNode.resize(20 * N, INT_MIN);
    rNode.resize(20 * N, INT_MIN);
  }

  void Update(long long h, long long v) { Update(h, v, 1, 1, N); }

  void Update(long long h, long long v, int now, int l, int r) {
    if (l == h && h == r) {
      val[now] = v;
      return;
    }
    long long mid = (l + r) >> 1;
    if (h <= mid) {
      if (lNode[now] == INT_MIN) lNode[now] = index++;
      Update(h, v, lNode[now], l, mid);
    } else {
      if (rNode[now] == INT_MIN) rNode[now] = index++;
      Update(h, v, rNode[now], mid + 1, r);
    }
    if (lNode[now] != INT_MIN) val[now] = max(val[now], val[lNode[now]]);
    if (rNode[now] != INT_MIN) val[now] = max(val[now], val[rNode[now]]);
    debug(h, v, now, l, r, val[now]);
  }

  long long Query(int ql, int qr) { return Query(ql, qr, 1, 1, N); }

  long long Query(int ql, int qr, int now, int l, int r) {
    debug(ql, qr, now, l, r);
    if (qr < ql) return 0;
    if (ql == l && qr == r) {
      return val[now];
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
      if (lNode[now] == INT_MIN) return 0;
      return Query(ql, qr, lNode[now], l, mid);
    } else if (mid + 1 <= ql) {
      if (rNode[now] == INT_MIN) return 0;
      return Query(ql, qr, rNode[now], mid + 1, r);
    } else {
      long long lChild = 0;
      if (lNode[now] != INT_MIN) lChild = Query(ql, mid, lNode[now], l, mid);
      long long rChild = 0;
      if (rNode[now] != INT_MIN)
        rChild = Query(mid + 1, qr, rNode[now], mid + 1, r);
      return max(lChild, rChild);
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.setf(ios::fixed), cout.precision(9);
  int n;
  cin >> n;
  vector<long long> h(n), a(n);
  for (int i = 0; i < n; ++i) cin >> h[i];
  for (int i = 0; i < n; ++i) cin >> a[i];

  SegmentTree st;
  vector<long long> dp(n);
  for (int i = 0; i < n; ++i) {
    debug(i);
    long long prevVal = st.Query(1, h[i] - 1);
    debug("Get: ", prevVal);
    dp[i] = prevVal + a[i];
    st.Update(h[i], dp[i]);
  }
  debug(dp);
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}
