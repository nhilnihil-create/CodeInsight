#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()
#define STRINGIFY(n) #n
#define TOSTRING(n) STRINGIFY(n)
#define PREFIX "#" TOSTRING(__LINE__) "| "
#define debug(x) \
{ \
  std::cout << PREFIX << #x << " = " << x << std::endl; \
}

std::ostream& output_indent(std::ostream& os, int ind) {
  for(int i = 0; i < ind; i++) os << " ";
  return os;
}

template<class S, class T> std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p);
template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);

template<class S, class T> std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p) {
  return (os << "(" << p.first << ", " << p.second << ")");
}
template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  for(int i = 0;i < v.size();i++) os << v[i] << ", ";
  return (os << "]");
}

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) { return std::vector<T>(n, std::forward<T>(val)); }
template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}
template<class Cond> struct chain {
  Cond cond; chain(Cond cond) : cond(cond) {}
  template<class T> bool operator()(T& a, const T& b) const { if(cond(a, b)) { a = b; return true; } return false; }
};
template<class Cond> chain<Cond> make_chain(Cond cond) { return chain<Cond>(cond); }

int main() {
  string S;
  cin >> S;
  i64 K;
  cin >> K;
  i64 N = S.size();
  auto dp = ndvec(N + 1, N + 1,K + 1, i64(0));
  rep(i,0,N) {
    dp[i][i + 1][0] = 1;
  }
  auto chmax = make_chain(std::less<i64>());
  rep(len,2,N + 1) {
    rep(l,0,N) {
      i64 r = l + len;
      if(r > N) break;
      i64 cost;
      if(S[l] == S[r - 1]) cost = 0;
      else                 cost = 1;
      rep(k,0,K + 1) {
        if(k - cost >= 0) {
          chmax(dp[l][r][k], dp[l + 1][r - 1][k - cost] + 2);
        }
        chmax(dp[l][r][k], dp[l + 1][r][k]);
        chmax(dp[l][r][k], dp[l][r - 1][k]);
      }
    }
  }
  cout << *max_element(all(dp[0][N])) << endl;
}
