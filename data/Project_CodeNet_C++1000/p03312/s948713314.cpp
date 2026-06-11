#include <bits/stdc++.h>
 
using namespace std;
 
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
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
  for (const auto &x : v) {
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
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<long long> sum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }
  
  long long ans = 5e16, half;
  for (int i = 1; i < n - 1; i++) {
    // [0, i] + [i + 1, n - 1]
    int l, r;
    half = (sum[i + 1] + 1) / 2;
    l = lower_bound(sum.begin(), sum.end(), half) - sum.begin();
    half = (sum[n] - sum[i + 1] + 1) / 2 + sum[i + 1];
    r = lower_bound(sum.begin(), sum.end(), half) - sum.begin();
    for (int j : {l - 1, l}) {
      for (int k : {r - 1, r}) {
        long long p, q, r, s;
        p = sum[j];
        q = sum[i + 1] - sum[j];
        r = sum[k] - sum[i + 1];
        s = sum[n] - sum[k];
        ans = min(ans, max({p, q, r, s}) - min({p, q, r, s}));
      }
    }
    
  }

  cout << ans << '\n';

  return 0;
}
