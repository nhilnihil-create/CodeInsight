#pragma GCC target("avx2")
#pragma GCC optimize("O3")
   
#include <x86intrin.h>
#include <bits/stdc++.h>   
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
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
#define al 0x3F3F3F3F
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
//#define int long long
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 123;
const ll inf = (ll)1e18 + 1;

const double pi = acos (-1.0);
const double eps = 1e-7;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

int n, a[N];
ll pref[N], ans = inf;

inline ll get (int l, int r) {
   return pref[r] - pref[l - 1];
}

inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     

inline void Solve () {
   cin >> n;
   for (int i = 1; i <= n; i ++) cin >> a[i], pref[i] = pref[i - 1] + a[i];
   int it1 = 1, it2 = 1;
   for (int i = 3; i <= n; i ++) {
      int l = 1, r = i - 2;
      while (it2 < i) it2 ++;
      while (it1 + 2 <= i - 1 && abs (get (1, it1 + 1) - get (it1 + 2, i - 1)) < abs (get (1, it1) - get (it1 + 1, i - 1))) it1 ++;
      while (it2 + 2 <= n && abs (get (i, it2 + 1) - get (it2 + 2, n)) < abs (get (i, it2) - get (it2 + 1, n))) it2 ++;
      ll B = get (1, it1);
      ll C = get (it1 + 1, i - 1);
      ll D = get (i, it2);
      ll E = get (it2 + 1, n);
      ans = min (ans, max (max (B, C), max (D, E)) - min (min (B, C), min (D, E)));
   }
   cout << ans;

}

main () {                                       
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
                          