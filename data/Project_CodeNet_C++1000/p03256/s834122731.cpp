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

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<i64> strongly_connected_components(const vector<vector<i64>>& g) {
  i64 n = g.size();
  vector<vector<i64>> rg(n);
  for(int i = 0;i < n;i++) {
    for(auto j: g[i]) {
      rg[j].push_back(i);
    }
  }

  vector<bool> vis(n,false);
  vector<i64> vs;
  vector<i64> res(n,-1);
  function<void(int)> dfs = [&](int v) {
    vis[v] = true;
    for(auto& t : g[v]) {
      if(!vis[t]) dfs(t);
    }
    vs.push_back(v);
  };

  function<void(int,int)> rdfs = [&](int v,int k) {
    vis[v] = true;
    res[v] = k;
    for(auto to : rg[v]) {
      if(!vis[to]) rdfs(to,k);
    }
  };

  for(int i = 0;i < n;i++) {
    if(!vis[i]) dfs(i);
  }

  vis.assign(n,false);
  int k = 0;
  for(int i = n - 1;i >= 0;i--) {
    if(!vis[vs[i]]) rdfs(vs[i] , k++);
  }
  return res;
}

int main() {
  i64 N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  vector<vector<i64>> g(N * 2);
  rep(e,0,M) {
    i64 a, b;
    cin >> a >> b;
    a--;
    b--;
    if(a == b) {
      g[a * 2].push_back(a * 2 + 1);
    }
    else if(S[a] == S[b]) {
      g[a * 2].push_back(b * 2 + 1);
      g[b * 2].push_back(a * 2 + 1);
    }
    else {
      g[a * 2 + 1].push_back(b * 2);
      g[b * 2 + 1].push_back(a * 2);
    }
  }
  auto res = strongly_connected_components(g);
  if(2 * N - 1 == *std::max_element(all(res))) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
