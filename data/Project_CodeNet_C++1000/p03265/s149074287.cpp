#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
# define mp make_pair
# define pb push_back
# define PI acos(-1)
# define ld long double
# define FOR(i,a,b) for(int i = a ; i < b ; ++i)
# define RFOR(i,a,b) for(int i = a ; i >= b ; --i)
# define all(a) a.begin(),a.end() 
const int MxN = 10000 ; 
const int MOD = 1e9 + 7 ; 

/* VARIABLES */
VI adj[MxN] ; 
vector<bool> vis(MxN) ; 
/* END OF VARIABLES */

void dfs(int u) {
	vis[u] = true ; 
	for(int x : adj[u]) {
		if(!vis[x])
			dfs(x) ; 
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;  
	int x1,x2,y1,y2 ; 
	cin >> x1 >> y1 >> x2 >> y2 ; 
	int xdis = x2 - x1 ; 
	int ydis = y2 - y1 ; 
	cout << x2 - ydis << " " << y2 + xdis << " " << x1 - ydis << " " << y1 + xdis ; 

	return 0 ; 
}

