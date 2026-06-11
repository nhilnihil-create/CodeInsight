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

constexpr char KURO = '#';
constexpr char SHIRO = '.';

struct Tmp
{
public:
  int H, W;
  vector<vector<char>> table;
  using P = pair<int, int>;
  P nextShiroNuruPos;
  P nextKuroNuruPos;
  Tmp(int H, int W);
  void doKuro();
  void doShiro();
};

Tmp::Tmp(int H = 100, int W = 100)
  : H(H)
  , W(W)
  , table(H, vector<char>(W))
  , nextShiroNuruPos(0, 1)
  , nextKuroNuruPos(H-1, 1)
{
  for (int i = 0; i <= H/2; ++i) {
    for (auto& c : table[i]) {
      c = KURO;
    }
  }
  for (int i = H/2+1; i < H; ++i) {
    for (auto& c : table[i]) {
      c = SHIRO;
    }
  }
}

void Tmp::doKuro()
{
  auto& p = nextKuroNuruPos;
  table[p.first][p.second] = KURO;
  p.second += 2;
  if (p.second >= W) {
    p.first -= 2;
    p.second = 1;
  }
  nextKuroNuruPos = p;
  return;
}

void Tmp::doShiro()
{
  auto& p = nextShiroNuruPos;
  table[p.first][p.second] = SHIRO;
  p.second += 2;
  if (p.second >= W) {
    p.first += 2;
    p.second = 1;
  }
  nextShiroNuruPos = p;
  return;
}

void solve(void)
{
  int A, B; cin >> A >> B;
  Tmp t{50, 100};
  for (int _ = 0; _ < A-1; ++_) {
    t.doShiro();
  }
  for (int _ = 0; _ < B-1; ++_) {
    t.doKuro();
  }

  cout << t.H << SPACE << t.W << CRLF;
  for (const auto& row : t.table) {
    for (const auto& c : row) {
      cout << c;
    }
    cout << CRLF;
  }
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
