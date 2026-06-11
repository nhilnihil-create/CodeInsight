#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

#ifdef _DEBUG
inline void dump() { cerr << endl; }
template<typename Head> void dump(Head&& head) { cerr << head; dump(); }
template<typename Head, typename... Tail> void dump(Head&& head, Tail&&... tail) { cerr << head << ", "; dump(forward<Tail>(tail)...); }
#define debug(...) do {cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; dump(__VA_ARGS__); } while (false)
#else
#define dump(...)
#define debug(...)
#endif

template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////

const ll inf = 1LL<<60;

int main()
{
  string s,t; cin>>s>>t;
  ll n = s.size();

  vector<int> ms(26, -1);
  vector<int> mt(26, -1);

  bool flg = true;
  rep(i, n) {
    int ns = s[i] - 'a';
    int nt = t[i] - 'a';
    if (ms[ns] < 0) ms[ns] = nt;
    if (mt[nt] < 0) mt[nt] = ns;
    if (ms[ns] != nt) flg = false;
    if (mt[nt] != ns) flg = false;
  }
  if (flg) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
