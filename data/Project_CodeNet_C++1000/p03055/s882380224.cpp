//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define F first
#define S second
#define pb push_back
#define bit __builtin_popcount
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mkp make_pair
#define ffs fflush(stdout)

using namespace std;
using namespace __gnu_pbds;

//order_of_key(k) : Number of items strictly smaller than k
//find_by_order(k) : K-th element in a set (counting from 0)

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef vector <int> lnum;
typedef pair <int, int> pii;

const int N = (int)1e6 + 5;
const int MOD = (int)1e9 + 7;
const int inf = (int)1e18;
const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
const ld eps = 1e9 - 7;
const int pp[] = {29, 31, 53, 67, 71};
const double pi = acos(-1.0);

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

int u[N];
vector <int> g[N];

signed main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  queue <int> q;
  vector <int> d(n + 1);
  q.push(1);
  u[1] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto to : g[v]) {
      if (!u[to]) {
        q.push(to);
        d[to] = d[v] + 1;
        u[to] = 1;
      }
    }
  }
  int f = 1;
  for (int i = 1; i <= n; ++i) {
    if (d[i] > d[f])
      f = i;
  }
  for (int i = 1; i <= n; ++i)
    u[i] = 0;
  for (int i = 1; i <= n; ++i)
    d[i] = 0;
  q.push(f);
  u[f] = 1;
  while (!q.empty()) {
    int v=  q.front();
    q.pop();
    for (auto to : g[v]) {
      if (!u[to]) {
        q.push(to);
        d[to] = d[v] + 1;
        u[to] = 1;
      }
    }
  }
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] > mx)
      mx = d[i];
  }
  if (mx % 3 == 1)
    cout << "Second";
  else
    cout << "First";
  return 0;
}
