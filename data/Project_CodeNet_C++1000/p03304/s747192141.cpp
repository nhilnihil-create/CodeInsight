/*
g++ --std=c++17 A.cpp
*/

#include <iostream>
#include <iomanip> //! for setprecision(20)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int INF = 1000000000;
const int MOD = 1000000007;

/*
  == AC Library Cheat sheet
  documentation: file:///Users/nobu/Downloads/ac-library/document_ja/index.html

  mint
    mint m.pow(int p)  //! return m^p
    mint m.inv() //! returns i that gives (m * i).val() == 1 
    int m.val() 

  fenwick_tree (BIT)
    fenwick_tree<T> fw(int n) //! init a[0] .. a[n-1] with all 0
    void fw.add(int idx, T x); //! a[idx] += x
    T fw.sum(int l, int r); //! return a[l] + .. + a[r-1]

  dsu (UnionFind)
    dsu d(int n)  //! prepare dsu with n nodes
    void d.merge(int x, int y)  //! connect node x and y
    bool d.same(int x, int y)  //! return true if node x and y are connected
    int d.leader(int x)  //! return the leader node of the connected group
    int d.size(int x) //! return the size of the group that node x belongs to
    vector<vector<int>> d.groups() //! return a vector of vectors that contain the nodes in each group

  scc_graph
    scc_graph　g(int n)  //! create a directed graph with n nodes
    g.add_edge(int from, int to)  //! create a directed edge from node from to node to
    vector<vector<int>> g.scc()  //! return the vector of strongly connected components that are topologically sorted

  segtree
    segtree<S, op, e>
      S: type of the monoid 
      op: function to return the product of two elements
      e: function to return the identity element such that op(x, e) == x fo any x 

  lazy_segtree
    lazy_segtree<S, op, e, F, mapping, composition, id>
      F: type of parameters to define the operation applied to the target elements
      mapping: function to return the element after applying the operation to the target element
      composition: function to combine the two sets of operation parameters to one
      id: function to return the operation parameter i such that mapping(i, x) = x for any x

      using S = int;
      S op(S a, S b) { return min(a, b); }
      S e() { return INF; }
      using F = int;
      S mapping(F f, S x) { return min(f, x); }
      F composition(F f, F g) { return min(f, g); }
      F id() { return INF; }

  floor_sum(ll n, ll m, ll a, ll b)   
*/



int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m, d;
  cin >> n >> m >> d;

  double p = 0;
  if (d == 0) {
    p = 1.0 / n;
  } else {
    p = 2.0 * (n-d) / n / n;
  }

  double ans = p * (m-1);

  cout << setprecision(20) << ans << endl;

  return 0;
}
