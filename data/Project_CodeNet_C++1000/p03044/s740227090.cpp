#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <bitset>
#include <numeric>
#include <array>
#include <cstring>
#include <random>
#include <chrono>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 42;
int ans[N];
vector<pair<int, int> > g[N];
void dfs(int v, int p) {
  for(auto& x : g[v])
    if(x.fi != p) {
      ans[x.fi] = (ans[v] ^ (x.se % 2));
      dfs(x.fi, v);
    }
}
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n = 0;

  cin >> n;

  for(int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].pb(mp(v, w));
    g[v].pb(mp(u, w));
  }

  ans[0] = 0;

  dfs(0, -1);

  for(int i = 0; i < n; i++) cout << ans[i] << endl;

  return 0;
}
/*

*/
