#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
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
  string s; cin>>s;

  string t;
  vector<int> a;
  int tmp = 0;
  for (auto c:s) {
    if (c != 'x') {
      t.push_back(c);
      a.push_back(tmp);
      tmp = 0;
    } else {
      tmp++;
    }
  }
  a.push_back(tmp);

  string u = t;
  reverse(t.begin(), t.end());
  if (t != u) {
    cout << -1 << endl;
    return 0;
  }

  int n = a.size();
  int ans = 0;
  for (int i=0; i<n/2; i++) {
    ans += abs(a[i]-a[n-i-1]);
  }
  cout << ans << endl;

  return 0;
}
