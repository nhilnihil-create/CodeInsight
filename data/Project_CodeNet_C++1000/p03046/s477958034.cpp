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

signed main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int m, k;
  cin >> m >> k;
  if (k == 0) {
    for (int i = 0; i < (1 << m); ++i)
      cout << i << " " << i << " ";
    return 0;
  }
  if (k > (1 << m) - 1 || (m == 1 && k == 1)) {
    cout << -1;
    return 0;
  }
  cout << 0 << " " << k << " " << 0 << " ";
  for (int i = 1; i < (1 << m); ++i) {
    if (i != k)
      cout << i << " ";
  }
  cout << k << " ";
  for (int i = (1 << m) - 1; i >= 1; i--) {
    if (i != k)
      cout << i << " ";
  }
  return 0;
}
