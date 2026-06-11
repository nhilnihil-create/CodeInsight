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
typedef pair <ll, ll>                                    pll;
 
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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

ll n, sz[xn], D[xn], ord[xn], cnt, H[xn], sum;
vector <pii> ans;
unordered_map <ll, int> mp;
vector <int> adj[xn];
bool mark[xn];

bool cmp(int i, int j){ return D[i] > D[j];}
void DFS(int v){
	mark[v] = true;
	++ cnt;
	sum += H[v];
	for (int u : adj[v]){
		if (mark[u]) continue;
		H[u] = H[v] + 1;
		DFS(u);
	}
}

int main(){
    InTheNameOfGod;
    
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> D[i];
		ord[i] = i;
		sz[i] = 1;
		mp[D[i]] = i;
	}
	sort(ord + 1, ord + n + 1, cmp);
	for (int i = 1; i < n; ++ i){
		int v = ord[i];
		int par = mp[D[v] - n + sz[v] + sz[v]];
		if (!par) kill(- 1);
		ans.push_back({v, par});
		adj[par].push_back(v);
		adj[v].push_back(par);
		sz[par] += sz[v];
	}
	DFS(1);
	if (cnt < n || sum != D[1]) kill(- 1);
	for (pii e : ans) cout << e.A << sep << e.B << endl;
 
    return 0;
}
