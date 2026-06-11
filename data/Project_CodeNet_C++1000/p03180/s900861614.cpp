/*
 *    author:  Gary Shih
 *    created: 2020-05-06 15:57:01
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

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.setf(ios::fixed), cout.precision(9);
  int n;
  cin >> n;
  vector<vector<long long>> a(n, vector<long long>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> a[i][j];

  vector<long long> dp(1 << n);

  for (int i = 1; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        if ((i & (1 << j)) && (i & (1 << k))) dp[i] += a[j][k];
    dp[i] /= 2;
    dp[i] = max(dp[i], 0ll);
  }
  for (int i = 1; i < (1 << n); ++i) {
    if (__builtin_popcount(i) <= 2) continue;
    vector<bool> choose(n);
    function<void(int, int)> dfs = [&](int now, int subMask) {
      if (now == n) {
        dp[i] = max(dp[i], dp[subMask] + dp[i - subMask]);
        return;
      }
      dfs(now + 1, subMask);
      if (i & (1 << now)) dfs(now + 1, subMask + (1 << now));
    };
    dfs(0, 0);
  }
  cout << dp.back() << '\n';
}
