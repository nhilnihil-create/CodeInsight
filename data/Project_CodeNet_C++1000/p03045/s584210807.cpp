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
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

vi g[1000005];
int  n, m ,cnt = 0; 
bool vis[1000005];

void dfs(int u){
	if (vis[u]) return ; 
	cnt++;
	vis[u] = true;
	for (auto &it: g[u]){
		if (!vis[it]) dfs(it);
	}
}

signed main()
{
    cin >> n >> m ; 
    while (m--){
    	int a,b,c; cin >> a >> b >> c;
    	g[a].pb(b);
    	g[b].pb(a);
    }
    int ans=n;
    for (int i=1;i<=n;i++){
    	cnt = 0 ; 
    	dfs(i);
    	if (cnt>1) ans -= (cnt-1);
    }
    cout << ans << endl;
    return 0;
}
