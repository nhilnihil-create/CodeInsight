#include <bits/stdc++.h>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define INF (1 << 29)
#define LLINF (1LL << 60)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;

string to_string(string s) { return s; }
template <class S>
string to_string(unordered_set<S> s);
template <class S>
string to_string(set<S> s);
template <class S, class T>
string to_string(map<S, T> m);
template <class T>
string to_string(vector<T> v);

template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

template <class S>
string to_string(unordered_set<S> s) {
  string ret = "{";
  for (S x : s) ret += to_string(x) + ",";
  return ret + "}";
}

template <class S>
string to_string(set<S> s) {
  string ret = "{";
  for (S x : s) ret += to_string(x) + ",";
  return ret + "}";
}

template <class S, class T>
string to_string(map<S, T> m) {
  string ret = "{";
  for (pair<S, T> x : m) ret += to_string(x) + ",";
  return ret + "}";
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < (int)v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() { cerr << endl; }

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() { cout << endl; }

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

int main() {
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<ll> a(N), acc(N + 1);
  FOR(i, N) cin >> a[i];
  FOR(i, N) acc[i + 1] = acc[i] + a[i];
  vector<ll> b;
  for (int i = 0; i < N; ++i)
    for (int j = i; j < N; ++j) b.push_back(acc[j + 1] - acc[i]);
  ll ans = 0;
  for (int i = 40; i >= 0; --i) {
    int cnt = 0;
    vector<ll> ok, ng;
    for (ll x : b)
      if ((x >> i) & 1LL) {
        cnt++;
        ok.push_back(x);
      }
    if (cnt >= K) {
      b = ok;
      ans |= (1LL << i);
    }
  }
  cout << ans << endl;
  return 0;
}