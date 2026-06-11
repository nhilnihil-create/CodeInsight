#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 2e5 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;


vector<pll> G[N] ; 
ll in[N]  , H[N] ; 
struct Event{
	ll l , r , len ;
}E[N];

void DFS (ll x , ll h = 1) {
	H[x] = h;
	for (auto u : G[x]) {
		if (!H[u.F])
			DFS(u.F , h + u.S) ;
	}
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll n , m;
    cin >> n >> m ;
    for (int i = 1 ; i <= m ; i ++) {
    	cin >> E[i].l >> E[i].r >> E[i].len;
    	G[E[i].l].pb({E[i].r , E[i].len}) ;
    	in[E[i].r] = 1 ;
	}
	ll cnt = 0 ;
	for (int i = 1;  i <= n ; i ++) {
		if (!in[i]) DFS(i) ;
		else cnt ++ ;
	}
	//cout << H[1] << ' ' << H[2] << endl;
	for (int i = 1 ; i <= m ; i ++) {
		if (H[E[i].l] + E[i].len != H[E[i].r] || cnt == n) return cout << "No" , 0 ;
	}
	cout << "Yes" ;
    
    return (0) ;
}