#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/integer/common_factor.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using std::string;
using std::vector;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::multimap;
using std::unordered_map;
using std::pair;
using std::cin;
using std::cout;

using boost::multiprecision::cpp_int;
using cpp_dec_float_1000 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000>>;

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

constexpr char CRLF  = '\n';
constexpr char SPACE = ' ';
constexpr char VECTOR_COUT_SEPARATOR = SPACE;
constexpr ll INF = 1000'000'007;
constexpr int MOD = 1000'000'007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& vc) { for(auto it = vc.begin(); it != vc.end(); ++it) { if (std::next(it) == vc.end()) os << *it; else os << *it << VECTOR_COUT_SEPARATOR; } return os; }
template<class T1, class T2> inline std::ostream & operator<< (std::ostream & os, const std::pair<T1, T2> & p) { return os << p.first << ' ' << p.second; }
template<class T> T modinv(T a, T m) { T b = m, u = 1, v = 0; while (b) { T t = a / b; a -= t * b; boost::swap(a, b); u -= t * v; boost::swap(u, v); } u %= m; if (u < 0) u += m; return u; }

struct Tmp
{
public:
  using T = ll;
  vector<T> A;
  vector<T> dpF;
  vector<T> dpG;
  int N;
  T K;
  Tmp(int N, T K)
    : A(N)
    , dpF(65, -1)
    , dpG(65, -1)
    , N(N)
    , K(K)
  {}
  T operator() () {
    return recF(64);
  }
  T recF(int n) {
    if (n == 0) {
      return dpF[n] = 0;
    }
    if (dpF[n] != -1) {
      return dpF[n];
    }
    T ret0{}, ret1{};

    T k = 1L << (n-1);
    for (int i = 0; i < N; ++i) {
      ret0 += (A[i] & k);
      ret1 += (A[i] & k) ^ k;
    }

    if ((k & K) != 0) {
      return dpF[n] = std::max(
        (ret0 + std::max(recF(n-1), recG(n-1))),
        (ret1 + recF(n-1))
      );
    } else {
      return dpF[n] = ret0 + recF(n-1);
    }
  }

  T recG(int n) {
    if (n == 0) {
      return dpG[n] = 0;
    }
    if (dpG[n] != -1) {
      return dpG[n];
    }
    T ret0{}, ret1{};

    T k = 1L << (n-1);
    for (int i = 0; i < N; ++i) {
      ret0 += (A[i] & k);
      ret1 += (A[i] & k) ^ k;
    }
    return dpG[n] = std::max(ret0, ret1) + recG(n-1);
  }
};

void solve(void)
{
  int N; cin >> N;
  ull K; cin >> K;
  Tmp t(N, K);
  for (auto& a : t.A) {
    cin >> a;
  }
  auto ans = t();
  cout << ans << CRLF;
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
