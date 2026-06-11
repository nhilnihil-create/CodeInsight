#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 i = (s);(i) < (e);(i)++)
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
template<class T, class V> std::ostream& operator<<(std::ostream& os, const std::map<T, V>& v) {
  os << "{";
  for(auto p: v) os << p << ", ";
  return (os << "}");
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
  i64 N;
  cin >> N;
  vector<i64> A(N);
  rep(i,0,N) cin >> A[i];

  auto func = [&](i64 K) {
    map<i64, i64> mp;
    mp[0] = 0;
    rep(i,1,N) {
      i64 b = A[i - 1];
      i64 a = A[i];
      if(b < a) {
        auto iter = mp.end();
        --iter;
        if(iter->second > 0) {
          mp[b] = 0;
        }
      }
      else {
        i64 j = a - 1;
        while(j >= 0) {
          auto iter = mp.upper_bound(j);
          --iter;
          i64 x = iter->second;
          if(x + 1 == K) {
            j = iter->first - 1;
            mp.erase(iter);
          }
          else {
            mp[j] = x + 1;
            mp[j + 1] = 0;
            break;
          }
        }
        if(j <= -1) {
          return false;
        }
        auto iter = mp.lower_bound(a);
        while(iter != mp.end()) {
          mp.erase(iter++);
        }
      }
    }
    return true;
  };

  i64 ok = N;
  i64 ng = 0;
  while(abs(ng - ok) > 1) {
    i64 m = (ok + ng) >> 1;
    if(func(m)) {
      ok = m;
    }
    else {
      ng = m;
    }
  }
  cout << ok << endl;
}
