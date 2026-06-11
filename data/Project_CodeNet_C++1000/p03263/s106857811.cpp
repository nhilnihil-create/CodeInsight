#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
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
  int h,w; cin>>h>>w;
  vector<vector<ll>> a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin>>a[i][j];

  vector<vector<int>> ans;
  for (int i=0; i<h; i++) {
    if (i%2 == 0) {
      for (int j=0; j<w-1; j++) {
        if (a[i][j]%2 == 1) {
          a[i][j]--;
          a[i][j+1]++;
          ans.push_back({i, j, i, j+1});
        }
      }
      if (i < h-1 && a[i][w-1]%2 == 1) {
        a[i][w-1]--;
        a[i+1][w-1]++;
        ans.push_back({i, w-1, i+1, w-1});
      }
    } else {
      for (int j=w-1; j>=1; j--) {
        if (a[i][j]%2 == 1) {
          a[i][j]--;
          a[i][j-1]++;
          ans.push_back({i, j, i, j-1});
        }
      }
      if (i < h-1 && a[i][0]%2 == 1) {
        a[i][0]--;
        a[i+1][0]++;
        ans.push_back({i, 0, i+1, 0});
      }
    }
  }
  cout << ans.size() << endl;
  for (auto v:ans) {
    printf("%d %d %d %d\n", v[0]+1, v[1]+1, v[2]+1, v[3]+1);
  }

  return 0;
}
