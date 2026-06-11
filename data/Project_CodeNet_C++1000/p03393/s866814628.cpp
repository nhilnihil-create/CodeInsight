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

  string z = "";
  rep(i, 26) z.push_back('z');
  string ans = z;

  vector<bool> used(26, false);
  int n = s.size();
  rep(i, n) {
    used[s[i]-'a'] = true;
    string t = s.substr(0, i);
    rep(j, 26) {
      if (used[j]) continue;
      string u = t + char('a' + j);
      if (s < u) ans = min(ans, u);
    }
  }
  rep(i, 26) {
    if (used[i]) continue;
    ans = min(ans, s + char('a' + i));
  }

  if (ans == z) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}
