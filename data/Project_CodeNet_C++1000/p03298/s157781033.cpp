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
  ll n; cin>>n;
  string s; cin>>s;
  string sl = s.substr(0, n);
  string sr = s.substr(n);
  map<pair<string, string>, ll> mpl;
  map<pair<string, string>, ll> mpr;
  for (int bits=0; bits<1<<n; bits++) {
    vector<string> al(2, "");
    for (int i=0; i<n; i++) {
      al[(bits>>i&1)].push_back(sl[i]);
    }
    reverse(al[1].begin(), al[1].end());
    mpl[make_pair(al[0], al[1])]++;
    vector<string> ar(2, "");
    for (int i=0; i<n; i++) {
      ar[(bits>>i&1)].push_back(sr[i]);
    }
    reverse(ar[1].begin(), ar[1].end());
    mpr[make_pair(ar[1], ar[0])]++;
  }
  ll ans = 0;
  for (auto v:mpl) {
    ans += v.second * mpr[v.first];
  }
  cout << ans << endl;

  return 0;
}
