#include <map>
#include <iostream>

struct range_valued_array {
  using key_type = int;
  using value_type = long long;
  using iterator_type = std::map<key_type, value_type>::iterator;

  std::map<key_type, value_type> mp;
  key_type len;

  range_valued_array(): len(0) {}

  void resize_with(key_type new_len, const value_type& val) {
    if(new_len == 0) mp.clear();
    else if(len < new_len) mp[new_len] = val;
    else if(len > new_len) {
      auto iter = inner_split(new_len);
      mp.erase(iter, mp.end());
    }
    len = new_len;
  }

  iterator_type inner_split(key_type pos) {
    if(pos == 0) return mp.begin();
    auto iter = mp.lower_bound(pos);
    if(iter->first == pos) return ++iter;
    mp[pos] = iter->second;
    return iter;
  }

  iterator_type range_set_value(key_type l, key_type r, const value_type& val) {
    if(l == r) return mp.end();
    auto liter = inner_split(l);
    auto riter = inner_split(r);
    mp.erase(liter, riter);
    return mp.insert({r, val}).first;
  }

  iterator_type begin() {
    return mp.begin();
  }
  iterator_type end() {
    return mp.end();
  }

  void debug_print() {
    std::cout << "[";
    for(auto p: mp) {
      std::cout << p.first << ": " << p.second << ", ";
    }
    std::cout << "]" << std::endl;
  }
};

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
    range_valued_array arr;
    arr.resize_with(A[0], 0);
    //cout << K << " ---" << endl;
    rep(i,1,N) {
      i64 b = A[i - 1];
      i64 a = A[i];
      //cout << i << " -> ";
      //arr.debug_print();
      if(b < a) {
        arr.resize_with(a, 0);
      }
      else {
        arr.resize_with(a, 0);
        auto iter = arr.end();
        int e = a;
        while(1) {
          if(iter == arr.begin()) return false;
          --iter;
          if(iter->second + 1 == K) {
          }
          else {
            e = iter->first;
            arr.range_set_value(iter->first - 1, iter->first, iter->second + 1);
            break;
          }
        }
        arr.range_set_value(e, a, 0);
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
