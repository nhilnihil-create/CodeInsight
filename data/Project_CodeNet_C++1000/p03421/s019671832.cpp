//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
 
//#include <x86intrin.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <bitset> 
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
//#include <ordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
//using namespace __gnu_pbds;
using namespace std;
 
//template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
#define F first
#define S second           
#define lb lower_bound               
#define ub upper_bound
#define pb push_back
#define pf push_front    
#define ppb pop_back
#define mp make_pair                                     
#define bpp __builtin_popcountll                                                                                        
#define sqr(x) ((x) * (x)) 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
#define int long long
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 123;
const ll inf = (ll)1e18 + 1;
 
const double pi = acos (-1.0);
const double eps = 1e-9;                  
const int dx[] = {0, 0, 1, 0, -1};                                                     
const int dy[] = {0, 1, 0, -1, 0};

int n, a, b;
vector <int> ans;

inline void boost () {
   ios_base :: sync_with_stdio (0);
   cin.tie (0), cout.tie (0);
}
 
inline void Solve () {
   cin >> n >> a >> b;
   if (!(a + b - 1 <= n && n <= a * b)) cout << -1, exit (0);
   for (int i = a; i >= 1; i --) ans.pb (i);
   if (b != 1) {
      int len = (n - a) / (b - 1);
      int ost = (n - a) % (b - 1);
      int it = a + 1;
      for (int z = 1; z < b; z ++) {
         int kon = it + len - 1 + (ost > 0);
         it = kon + 1;
         for (int i = 1; i <= len + (ost > 0); i ++) ans.pb (kon --);
         ost --;
      }
   }
   reverse (all (ans));
   for (auto it : ans) cout << it << ' ';
}               
 
signed main () {                                       
  // #ifdef QWERTY
  //    freopen("input", "r", stdin);
   //#endif
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();
   int tt = 1;
   //cin >> tt;   
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}                   