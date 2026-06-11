
/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end()
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

vi  g[10005]; 
bool vis[10005];

inline void solve(){
	int n,ans = 0; cin>>n; 
    vi c(n),res(n+1); 
    for (int i=0;i<n-1;i++){ 
    	int  u, v ; 
    	cin >> u >> v ; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    } 
    for (int i=0;i<n;i++) cin >> c[i] ; 
    sort(all(c)) ; 
	int  i = n-2 ; 
    function < void(int) > dfs = [&] (int u){
    	if (vis[u]) return ; 
    	vis[u] = true;
    	for (auto &it: g[u]){
    		if (!vis[it]){
    			ans += c[i] ; 
    			res[it] = c[i] ; 
    			i--; 
    			dfs(it); 
    		}
    	}
    };
    res[1] = c[n-1] ; 
    dfs(1) ; 
    co (ans) ; 
    for (int i=1;i<=n;i++) 
    	cout << res[i] << " " ; 
    cout << endl; 
}

signed main()
{
    solve();
    return 0;
}
/* 

5 
1 2 
1 3 
3 4 
3 5 
2 3 4 5 6 

		ans -> 14 



*/