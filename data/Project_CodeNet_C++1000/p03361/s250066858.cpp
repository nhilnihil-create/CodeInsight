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
  ll h, w; cin>>h>>w;
  vector<string> s(h);
  rep(i, h) cin>>s[i];

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  rep(i, h) rep(j, w) {
    if (s[i][j] == '.') continue;
    bool isok = false;
    rep(k, 4) {
      int ni = i - dx[k];
      int nj = j - dy[k];
      if (ni<0||h<=ni||nj<0||w<=nj) continue;
      if (s[ni][nj] == '#') isok = true;
    }
    if (!isok) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
