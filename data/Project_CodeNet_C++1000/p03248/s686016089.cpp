# include <bits/stdc++.h>
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ld, ld>                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

//const ll md = 1e9 + 7;//998244353;
const int xn = 1e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int Md[3] = {1000000007, 987654319, 1000000009};
const int TM = 3;
const int Base = 257;

int n, Root = 1;
vector <int> adj[xn];
string s;

int main(){
    InTheNameOfGod;
    
    cin >> s;
    n = SZ(s);
    s = '.' + s;
    if (s[1] == '0' || s[n] == '1')		kill(-1);
    for (int i = 1; i < n; ++ i)	if (s[i] != s[n - i]) kill(-1);
    for (int i = 1; i < n; ++ i){
    	adj[Root].push_back(i + 1);
    	if (s[i] == '1')	Root = i + 1;
	}
	for (int v = 1; v <= n; ++ v) for (int u : adj[v])	cout << v << sep << u << endl;
	
    return 0;
}
