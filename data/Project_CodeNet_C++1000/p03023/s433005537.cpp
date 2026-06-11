// #include <bits/stdc++.h>
#include <iostream> // cin, cout, string
#include <algorithm> // sort, min, max
#include <vector>
#include <utility> // pair, swap
#include <functional>
#include <iomanip> // setprecision
#include <map>
#include <set> // multiset
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue> // priority_queue
#include <deque>
#include <bitset>
#include <complex>
#include <ratio>

using namespace std;

// #define int long long

using ll = long long;
using ld = long double;

// template<class T1, class T2> using P = pair<T1, T2>;
template<class T> using vec = vector<T>;
template<class T> using mat = vec<vec<T>>;
template<typename T> using func = function<T>;

using pii = pair<int, int>;
using ppi = pair<pii, int>;
using pip = pair<int, pii>;
using ppp = pair<pii, pii>;

using vi = vec<int>;
using mi = mat<vi>; // Graph
using vp = vec<pii>;

constexpr int IINF =  0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
// constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
constexpr long long MOD = 1e9+7;

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b)-1;i >= (a);--i)

#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)

#define pb push_back
// make_pair(A, B) == pair<T, U>(A, B)
#define mp make_pair
// tie(...) == mt(...)
#define mt make_tuple
// emplace_back(*) == push_back(constructor(*))
#define eb emplace_back
#define ft first
#define sd second

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a).size()
#define rev(a) reverse(all(a))
// #define sum(...) accumulate(range(__VA_ARGS__), 0LL)

#define endl '\n'
#define dec(n) fixed << setprecision(n)
#define zfl(n)  setfill(‘0’) << setw(n)
#define debug(x) cerr << #x << ": " << (x) << endl

template<typename T> T gcd(T a, T b) { if(a==0 || b==0) return 0; while(b) { a = a%b; swap(a, b); } return a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

template<typename T> istream &operator>>(istream &is, vector<T> &v) { for(auto&& x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for(int i=0; i<(int)v.size(); ++i) cout << v[i] << ( i+1 != (int)v.size() ? " " : "" ); return os; }

template<typename A, typename B> istream &operator>>(istream &is, pair<A, B> &p) { is >> p.first; is >> p.second; return is; }
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { os << p.first << " " << p.second; return os; }

inline auto yes(const bool &i) { return i ? "yes" : "no"; }
inline auto Yes(const bool &i) { return i ? "Yes" : "No"; }
inline auto YES(const bool &i) { return i ? "YES" : "NO"; }
inline auto Possible(const bool &i){ return i ? "Possible" : "Impossible"; }
inline auto POSSIBLE(const bool &i){ return i ? "POSSIBLE" : "IMPOSSIBLE"; }

const int limit = 100007;

int N;

signed main() {
  cin.tie(0);cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  cout << 180*(N-2) << endl;

  return 0;
}
