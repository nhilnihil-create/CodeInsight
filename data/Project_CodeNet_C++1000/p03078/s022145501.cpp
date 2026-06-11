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
  ios:: sync_with_stdio(false);
  cin.tie();
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<long long> a(x);
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  debug(a);
  vector<long long> b(x * y);
  int cur = 0;
  for (int i = 0; i < y; i++) {
    long long val;
    cin >> val;
    for (int j = 0; j < x; j++) {
      b[cur++] = a[j] + val;
    }
  }
  sort(b.rbegin(), b.rend());
  debug(b);
  vector<long long> c(z * (min((int)b.size(), k)));
  cur = 0;
  for (int i = 0; i < z; i++) {
    long long val;
    cin >> val;
    for (int j = 0; j < min((int)b.size(), k); j++) {
      c[cur++] = b[j] + val;
    }
  }
  sort(c.rbegin(), c.rend());
  debug(c);
  for (int i = 0; i < k; i++) {
    cout << c[i] << '\n';
  }
  return 0;
}


