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

struct S {
  int p, y, i;
};

bool comp(pair<int,int> a, pair<int,int> b)
{
  if (a.second != b.second) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

bool c1(S a, S b)
{
  if (a.p != b.p) {
    return a.p < b.p;
  }
  return a.y < b.y;
}

bool c2(S a, S b)
{
  return a.i < b.i;
}

int main()
{
  ll n, m; cin>>n>>m;
  vector<S> a(m);
  rep(i, m) {
    int p, y; cin>>p>>y;
    a[i] = S{p, y, i};
  }
  sort(a.begin(),a.end(), c1);
  a[0].y = 1;
  rep(i, m) {
    if (a[i].p == a[i-1].p) a[i].y = a[i-1].y+1;
    else a[i].y = 1;
  }
  sort(a.begin(),a.end(), c2);
  rep(i, m) {
    printf("%06d%06d\n", a[i].p, a[i].y);
  }

  return 0;
}
