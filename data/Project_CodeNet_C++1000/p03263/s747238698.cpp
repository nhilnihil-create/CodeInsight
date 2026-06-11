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
  int y1,x1,y2,x2;
};

int main()
{
  int h,w; cin>>h>>w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin>>a[i][j];

  int n = 0;
  vector<S> ans;

  for (int i=0; i<h; i++) {
    if (i % 2) {
      for (int j=w-1; j>=1; j--) {
        if (a[i][j] % 2) {
          a[i][j]--;
          a[i][j-1]++;
          ans.push_back(S{i, j, i, j-1});
          n++;
        }
      }
      if (i < h-1) {
        if (a[i][0] % 2) {
          a[i][0]--;
          a[i+1][0]++;
          ans.push_back(S{i, 0, i+1, 0});
          n++;
        }
      }
    } else {
      for (int j=0; j<w-1; j++) {
        if (a[i][j] % 2) {
          a[i][j]--;
          a[i][j+1]++;
          ans.push_back(S{i, j, i, j+1});
          n++;
        }
      }
      if (i < h-1) {
        if (a[i][w-1] % 2) {
          a[i][w-1]--;
          a[i+1][w-1]++;
          ans.push_back(S{i, w-1, i+1, w-1});
          n++;
        }
      }
    }
  }

  cout << n << endl;
  for (auto v:ans) {
    printf("%d %d %d %d\n", v.y1+1, v.x1+1, v.y2+1, v.x2+1);
  }

  return 0;
}
