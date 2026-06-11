#include <bits/stdc++.h>
using namespace std;

#define  range(i, l, r) for (int i = (int)(l); i < (int)(r); ++(i))
#define rrange(i, l, r) for (int i = (int)(r) - 1; i >= (int)(l); --(i))

#define  whole(f, x, ...) ([&](decltype((x)) container) { return (f)(  begin(container),  end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)

#define debug(x) cerr << "(" << __LINE__ << ")" << #x << ": " << (x) << endl

using int32 = int;
using int64 = long long;

const int   mod   = 1e9 + 7;
const int32 inf   = 1001001001;
const int64 infll = 1001001001001001001ll;

const int dx[] = { 0, -1,  1,  0, -1,  1, -1,  1}; 
const int dy[] = {-1,  0,  0,  1, -1, -1,  1,  1};

struct IoSetup { IoSetup(int x = 10){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;

template <typename T = int64> T input() { T x; cin >> x; return x; }

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) { range(i, 0, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); } return os; } 
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p) { os << p.first << " " << p.second; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }

template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

void solver() {
  int N = input();

  string s = "_" + input< string >();

  vector< int64 > rd(N + 1), rm(N + 1);
  range(i, 1, N + 1) {
    rd[i] = rd[i - 1] + (s[i] == 'D');
    rm[i] = rm[i - 1] + (s[i] == 'M');
  }

  int q = input();
  while (q--) {
    int k = input();
    int64 res = 0;

    int64 cnt = 0;
    range(i, 1, N + 1) {
      if (i - k >= 0 && s[i - k] == 'D') {
        cnt -= (rm[i] - rm[i - k]);
      }

      if (s[i] == 'M') {
        cnt += (rd[i] - rd[max(0, i - k - 1)]);
      }

      if (s[i] == 'C') res += cnt;
    }

    cout << res << endl;
  }
}

signed main(int argc, char *argv[]) {
  solver();
}
