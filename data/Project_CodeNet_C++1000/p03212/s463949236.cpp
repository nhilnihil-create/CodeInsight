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
const int MxN = 200001 ; 
const int MOD = 1e9 + 7 ; 

/* VARIABLES */
int n  ;
int ans ; 
/* END OF VARIABLES */

inline bool check(ll x) {
	int a=0,b=0,c=0 ; 
	while(x) {
		ll r = x %10 ; 
		if(r == 3)
			a++;
		else if(r == 5)
			b++;
		else if(r == 7)
			c++;
		x /= 10 ; 
	}
	if(a>0&&b>0&&c>0)
		return true ; 
	else 
		return false ; 
}

void dfs(ll v) {
	
	if(v > n ) 
		return ; 
	if(check(v))
		ans++;
	dfs(v*10 + 3) ;
	dfs(v*10 + 5) ;
	dfs(v*10 + 7) ; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;  

	cin >> n ; 
	dfs(0) ; 
	cout << ans ; 
	
	return 0 ; 
}

